#pragma once


#include "iostream"
#include "marketdata.hpp"
#include "../Queue/queue.hpp"



class Parser{
    public:
    static MarketData parse(Queue<std::string>& queue);
};