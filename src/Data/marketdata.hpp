#pragma once


#include "iostream"
#include "nlohmann/json.hpp"
#include "../HttpClient/httpclient.hpp"


namespace MarketData{
    
    struct MarketData{
        std::string market;
    };

    struct Ohlc : public MarketData{
        double open{};
        double high{};
        double low{};
        double close{};
    };

    struct Latest : public Ohlc {
        double bid{};
        double ask{};
        double last{};
        double dayDiffPercent{};
        double spread{};
        double mid{};
        int quoteAgeSeconds{};
        std::string marketState;
        std::string direction;
        std::string timestamp;

        void dump() const {
            nlohmann::json j = {
                {"market", market},
                {"high"}, high,
                {"low"}, low,
                {"bid", bid},
                {"ask", ask},
                {"last", last},
                {"state", marketState},
                {"spread", spread},
                {"time", timestamp}
            };
            std::cout << j.dump(4) << "\n";
        }
    };
}