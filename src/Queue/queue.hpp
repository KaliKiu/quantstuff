#pragma once
#include <iostream>
#include <queue>

template<typename T>
class Queue{
    public:
        void push(T value);
        T pop();

    private:

    std::queue<T> data;
};