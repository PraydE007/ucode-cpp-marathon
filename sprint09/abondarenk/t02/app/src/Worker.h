#pragma once

#include <thread>
#include <vector>
#include <utility>

class Worker {
 public:
    Worker() = default;
    Worker(const Worker&) = delete;
    ~Worker();

    Worker& operator=(const Worker&) = delete;

    template <typename Function, class... Args>
    void startNewThread(Function&& func, Args&&... args) {
        m_workerThreads.push_back(std::thread(func, args...));
    }

    void joinAllThreads();

 private:
    std::vector<std::thread> m_workerThreads;
};
