#pragma once

#include <string>

namespace Config{


    struct Config {
        std::string apiURL;
        std::string market_name;
    };
    extern Config config;
    
    void loadconfig(const char* CONFIG_FILE_DIR);

}