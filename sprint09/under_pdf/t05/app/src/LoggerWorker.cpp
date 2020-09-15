#include "LoggerWorker.h"

LoggerWorker::~LoggerWorker() {
    stop();
    m_condVar.notify_all();
    join();
    m_logFileStream.close();
}

LoggerWorker& LoggerWorker::getLogger() {
    static LoggerWorker worker;
    return worker;
}

void LoggerWorker::log(Log::LogLevel level, const std::string& logMessage) {
    {
        std::unique_lock<std::mutex> lock(m_runMutex);
        m_logQueue.push(LogMessage{logMessage, level});
    }
    m_condVar.notify_one();
}

LoggerWorker::LoggerWorker() {
    time_t curr_time;
    tm* curr_tm;
    char filename[100];
    time(&curr_time);
    curr_tm = localtime(&curr_time);
    strftime(filename, 50, "%d_%m_%YT%H_%M_%S.txt", curr_tm);

    m_logFileStream.open(filename);
    start();
}

void LoggerWorker::run() {
    time_t curr_time;
    tm* curr_tm;

    while (true) {
        std::unique_lock<std::mutex> lck(m_runMutex);
        m_condVar.wait(lck, [this] {
            return !this->isRunning() || !this->m_logQueue.empty();
        });
        if (!isRunning() && m_logQueue.empty())
            return;
        auto elem = m_logQueue.front();

        char tm_str[100];
        time(&curr_time);
        curr_tm = localtime(&curr_time);
        strftime(tm_str, 50, "[%d:%m:%YT%H:%M:%S] ", curr_tm);

        m_logFileStream << tm_str << '[';
        if (elem.logLevel == Log::LogLevel::Info)
            m_logFileStream << "Info";
        else if (elem.logLevel == Log::LogLevel::Debug)
            m_logFileStream << "Debug";
        else
            m_logFileStream << "Warning";
        m_logFileStream << "] " << elem.message << std::endl;
        m_logQueue.pop();
    }
}
