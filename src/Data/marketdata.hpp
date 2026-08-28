#pragma once

#include "../HttpClient/httpclient.hpp"
#include "iostream"

struct MarketData{
    double bid;
    double ask;
    double spread;
    double mid;
    std::string timestamp;
    std::string Market;
};