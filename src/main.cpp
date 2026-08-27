#include <iostream>
#include <curl/curl.h>
#include "HttpClient/httpclient.hpp"
#include "Config/config.hpp"

static constexpr const char* CONFIG_FILE_DIR =  "../data/config.json";

int main(){

    Config::loadconfig(CONFIG_FILE_DIR);
    
    int a = 2;
    HttpClient meow(2);
    meow.getData();
    
}

