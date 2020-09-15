#include "Worker.h"

Worker::~Worker() {
    joinAllThreads();
}

void Worker::joinAllThreads() {
    while (m_workerThreads.size() > 0) {
        auto it = m_workerThreads.begin();
        m_workerThreads[0].join();
        m_workerThreads.erase(it);
    }
}
