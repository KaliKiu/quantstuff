#include <mutex>
#include <condition_variable>
#include <iostream>
#include "queue.hpp"

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