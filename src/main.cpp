#include <iostream>
#include <curl/curl.h>
#include <thread>

#include "HttpClient/httpclient.hpp"
#include "Config/config.hpp"
#include "Queue/queue.hpp"
#include "Data/marketdata.hpp"
#include "Data/data.hpp"
#include "Data/parser.hpp"
#include "Analyze/analyzer.hpp"
#include "Analyze/momentumanalyzer.hpp"

static constexpr const char* CONFIG_FILE_DIR =  "../data/config.json";

int main(){
    Config::loadconfig(CONFIG_FILE_DIR);
    Queue<std::string> queue;
    HttpClient http;
    Data data;

    std::thread t([&http, &queue](){
        for(int i = 0; i<10; i++){
            http.pushData(queue);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    /*std::thread p([&data,&queue](){

    });*/
    

    if(t.joinable()){
        std::cout<<"thread joined";
        t.join();
    }
    std::thread p([&queue](){
        while(!queue.is_empty()){
            Parser::parse(queue);
        }
    });

    if(p.joinable()){
        std::cout <<"thread joined";
        p.join();
    }

    std::unique_ptr<Analyzer> ok = std::make_unique<MomentumAnalyzer>();

}

