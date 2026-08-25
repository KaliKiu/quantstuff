#include <string>
#include <curl/curl.h>
#include <iostream>
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

    void pullData(){
        CURL *curl;
        CURLcode res;
        char *buffer;
        curl = curl_easy_init();
        curl_easy_setopt(curl,CURLOPT_URL, "https://keepni.love");
        curl_easy_setopt(curl,CURLOPT_WRITEDATA, &buffer);
        
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        data = buffer;
        std::cout <<buffer;

    }

    int getId(){
        return id;
    }

    private:

};