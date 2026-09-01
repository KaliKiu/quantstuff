#pragma once

#include <string>

namespace Config{


    struct Config {
        std::string apiURL;
        std::string apiXAUUSD;
        std::string apiXAUUSD_OHLC;
    };
    extern Config config;
    
    void loadconfig(const char* CONFIG_FILE_DIR);

}