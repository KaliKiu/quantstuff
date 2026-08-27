#pragma once

#include <iostream>
#include <vector>
#include "../Result/result.hpp"
#include "marketdata.hpp"

class Analyzer{
    virtual Result analyze(std::vector<MarketData>& Data);
    virtual ~Analyzer() = default;
};