#pragma once


#include "iostream"
#include "marketdata.hpp"
#include "../Queue/queue.hpp"



class Parser{
    public:
    static MarketData::Latest parseLatest(Queue<std::string>& queue);
    static MarketData::Ohlc parseOhlc(Queue<std::string>& queue);
};