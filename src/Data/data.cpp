
#include "vector"
#include "iostream"
#include "marketdata.hpp"
#include "data.hpp"

void Data::addLatestData(MarketData&& data){
        std::lock_guard<std::mutex> lock(mutex);
        data.dump();
        HistoryData.push_back(std::move(data));
}

void Data::displayHistoryData(){
    for(auto& i : HistoryData){
        i.dump();
    }
}