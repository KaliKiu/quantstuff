#pragma once

#include "../HttpClient/httpclient.hpp"
#include "iostream"

struct MarketData{
    int prize;
    int timestamp;
    std::string Market;
};