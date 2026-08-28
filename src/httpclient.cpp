#include <string>
#include <curl/curl.h>
#include <iostream>
#include "Config/config.hpp"
#include "HttpClient/httpclient.hpp"


    HttpClient::HttpClient (){}

    HttpClient::~HttpClient(){

    }

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    std::string HttpClient::getData(){

        CURL *curl;
        CURLcode res;
        std::string buffer;

        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, Config::config.apiURL.c_str());
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA, &buffer);
        
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << buffer <<std::endl;
        std::cout << Config::config.apiURL <<std::endl;

        return buffer;

    }
