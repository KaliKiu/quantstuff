#pragma once
#include <iostream>
#include <queue>
#include <condition_variable>
#include <mutex>

template<typename T>
class Queue{
    public:
        void push(T value);
        T pop();

    private:

    std::queue<T> data;
    std::mutex mutex;
    std::condition_variable cv;
};