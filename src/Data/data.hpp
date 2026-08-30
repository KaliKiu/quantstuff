#pragma once

#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <type_traits>
#include "marketdata.hpp"



class Data{
    public:
    Data() = default;

    template <typename T>
    void addData(T&& data){
        static_assert(!std::is_lvalue_reference_v<T>, 
                  "ERROR: You must pass an rvalue! Use std::move() if passing a variable.");

        std::lock_guard<std::mutex> lock(mutex);
        
        //could use std::forward
        std::get<std::vector<std::decay_t<T>>>(historyData).push_back(std::move(data));
    }
    template <typename T>
    void displayHistoryData(){
        for(auto& i : std::get<std::vector<T>>(historyData)){
            i.dump();
        }
    }

    private:
    std::mutex mutex;
    //maybe later on use std::deque? idk if thats better

    std::tuple<
        std::vector<MarketData::Latest>,
        std::vector<MarketData::Ohlc>
        > historyData;
};