#pragma once


#include "iostream"
#include "marketdata.hpp"
#include "../Queue/queue.hpp"



class Parser{
    public:
    static MarketData parseOhlc(Queue<std::string>& queue, std::string market);
};