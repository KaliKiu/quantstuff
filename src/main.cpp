#include <iostream>
#include <curl/curl.h>
#include "getdata.cpp"
#include "include/config.hpp"

static constexpr char* CONFIG_FILE_DIR =  "/data/config.json";

int main(){

    Config::loadconfig(CONFIG_FILE_DIR);
    
    int a = 2;
    DataObj meow(2);
    
    std::cout<< meow.getId();
    meow.pullData();
    
}

