#pragma once

#include <iostream>
#include <vector>
#include "../Result/result.hpp"
#include "../Data/marketdata.hpp"

class Analyzer{
    public:
    virtual ~Analyzer() = default;
    virtual Result analyze(std::vector<MarketData>& Data) = 0;
    
};