#pragma once

#include "../HttpClient/httpclient.hpp"
#include "iostream"

struct MarketData{
    std::string market;
    double bid{};
    double ask{};
    double last{};
    double high{};
    double low{};
    double dayDiffPercent{};
    double spread{};
    double mid{};
    int quoteAgeSeconds{};
    std::string marketState;
    std::string direction;
    std::string timestamp;
};