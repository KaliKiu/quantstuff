#pragma once

#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include "marketdata.hpp"


class Data{
    public:
    
    Data() = default;
    void addLatestData(MarketData&& data);
    void displayHistoryData();
    private:
    std::mutex mutex;
    //maybe later on use std::deque? idk if thats better
    std::vector<MarketData> HistoryData;
};