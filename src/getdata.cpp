#include <string>
#include <curl/curl.h>
#include <iostream>
#include "include/config.hpp"

class DataObj{

    int id;
    char* data;
    public: 
    DataObj (){}
    DataObj(int id_) : id(id_)
    {
    }

    ~DataObj(){

    }

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    void pullData(){

        CURL *curl;
        CURLcode res;
        std::string buffer;

        curl = curl_easy_init();
        curl_easy_setopt(curl,CURLOPT_URL, "https://keepni.love/home");
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA, &buffer);
        
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        //std::cout << buffer <<std::endl;
        std::cout << Config::config.apiURL <<std::endl;

    }

    int getId(){
        return id;
    }

    private:

};