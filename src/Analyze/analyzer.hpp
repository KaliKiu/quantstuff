#pragma once

#include <iostream>
#include <vector>
#include <variant>
#include "../Result/result.hpp"
#include "../Data/marketdata.hpp"




class Analyzer{
    public:
    virtual ~Analyzer() = default;

    virtual Result analyze(std::vector<MarketData::StructType>& Data) = 0;
    
};