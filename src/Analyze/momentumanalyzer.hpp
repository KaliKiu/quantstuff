#pragma once

#include "analyzer.hpp"
#include "../Data/marketdata.hpp"

class MomentumAnalyzer : public Analyzer{
    public:
    MomentumAnalyzer() = default;
    ~MomentumAnalyzer() override = default;
    Result analyze(std::vector<MarketData::StructType>& Data) override;
};