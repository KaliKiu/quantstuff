#pragma once

#include <iostream>
#include <vector>
#include "marketdata.hpp"


class Data{
    std::vector<MarketData> HistoryData;

    Data();

    void addLatestData(MarketData Data);
};