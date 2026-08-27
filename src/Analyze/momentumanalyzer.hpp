#pragma once

#include "analyzer.hpp"

class MomentumAnalyzer : public Analyzer{
    Result analyze(std::vector<MarketData>& Data) override;
};