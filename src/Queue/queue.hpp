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
        bool is_empty();

    private:

    std::queue<T> data;
    std::mutex mutex;
    std::condition_variable cv;
};

template<typename T>
void Queue<T>::push(T value){
    {
    std::lock_guard<std::mutex> lock(mutex);
    //cast to r value
    data.push(std::move(value));
    }
    cv.notify_one();
}

template <typename T>
T Queue<T>::pop(){
    
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock,[this]{
            return !data.empty();
        });
    
        T value = std::move(data.front());
        data.pop();
        return value;
}

template <typename T>
bool Queue<T>::is_empty(){
    return data.empty();
}