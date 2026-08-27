#pragma once

#include "marketdata.hpp"
#include "iostream"


class Parser{
    static MarketData parse(const std::string& json);
};