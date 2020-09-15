#include "MultithreadedFileHandler.h"
#include <iostream>
#include <fstream>

void MultithreadedFileHandler::processFile() {
    std::unique_lock<std::mutex> mtx(m_mutex);
    m_condVar.wait(mtx, [this]{return m_fileLoaded;});

    std::cout << m_file << std::endl;
    m_fileLoaded = false;
}

void MultithreadedFileHandler::loadFile(const std::string& fileName) {
    std::ifstream fd(fileName);

    getline(fd, m_file, '\0');
    fd.close();
    m_fileLoaded = true;
    m_condVar.notify_one();
}
