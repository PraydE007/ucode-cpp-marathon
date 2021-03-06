#include "Worker.h"

void Worker::start() {
    if (!m_isRunning) {
        m_isRunning = true;
        m_worker = std::thread(&Worker::run, this);
    }
}

void Worker::stop() {
    m_isRunning = false;
}

void Worker::join() {
    m_worker.join();
}

bool Worker::isRunning() const {
    return m_isRunning;
}
