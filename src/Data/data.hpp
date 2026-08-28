#pragma once

#include <iostream>
#include <vector>
#include "marketdata.hpp"


class Data{
    public:
    
    Data() = default;
    void addLatestData(MarketData Data);

    private:
    std::vector<MarketData> HistoryData;
};