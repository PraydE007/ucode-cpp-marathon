#pragma once

#include <future>

class Worker {
 public:
    Worker() = default;
    Worker(const Worker&) = delete;
    ~Worker() = default;

    Worker& operator=(const Worker&) = delete;

    template <typename Function, class... Args>
    auto startAsync(Function&& func, Args&&... args) {
        return std::async(std::launch::async, func, args...);
    }
};
