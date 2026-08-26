#include <iostream>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <fstream>
#include "include/config.hpp"

using json = nlohmann::json;

namespace Config{

    Config config;

    void loadconfig(const char* CONFIG_FILE_DIR){
        std::ifstream config_file(CONFIG_FILE_DIR);
        if(!config_file.is_open()){
            std::cerr <<"error opening file";
            return;
        }
        json configjson = json::parse(config_file);
        config.apiURL = configjson["apiURL"];
        
    }

}  