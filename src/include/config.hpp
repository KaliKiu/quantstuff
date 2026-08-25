#pragma once

#include <string>

namespace Config{


    struct Config {
        std::string apiURL;
        std::string symbol;

    };
    
    extern Config config;

    void loadconfig(char* CONFIG_FILE_DIR);

}