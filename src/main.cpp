#include <iostream>
#include <curl/curl.h>
#include "getdata.cpp"
#include "include/config.hpp"

static constexpr const char* CONFIG_FILE_DIR =  "../data/config.json";

int main(){

    Config::loadconfig(CONFIG_FILE_DIR);
    
    int a = 2;
    DataObj meow(2);
    meow.pullData();
    
}

