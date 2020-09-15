#include "LoggerWorker.h"

Log::~Log() {
    LoggerWorker& logger = LoggerWorker::getLogger();
    logger.log(m_logLevel, m_inputStream.str());
}

Log Log::createLog(LogLevel level) {
    return Log(level);
}

Log::Log(LogLevel level) : m_logLevel(level) {}
