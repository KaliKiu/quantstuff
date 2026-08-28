#pragma once

#include "analyzer.hpp"

class MomentumAnalyzer : public Analyzer{
    public:
    MomentumAnalyzer() = default;
    Result analyze(std::vector<MarketData>& Data) override;
};