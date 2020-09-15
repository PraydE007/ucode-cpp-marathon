#include "Worker.h"

Worker::~Worker() {
    joinAllThreads();
}

void Worker::joinAllThreads() {
    for (auto & temp : m_workerThreads)
        temp.join();
    m_workerThreads.clear();
}
