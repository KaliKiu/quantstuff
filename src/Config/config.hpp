#pragma once

#include <string>

namespace Config{


    struct Config {
        struct XAUUSD{
            std::string apiXAUUSD;
            std::string apiXAUUSD_OHLC;
        } XAUUSD;
        struct BTCUSD{
            std::string apiBTCUSD;
            std::string apiBTCUSD_OHLC;
        } BTCUSD;
    };
    extern Config config;
    
    void loadconfig(const char* CONFIG_FILE_DIR);

}