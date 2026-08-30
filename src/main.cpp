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
        for(int i = 0; i<100000; i++){
            http.pushData(queue);
        }
    });

    if(t.joinable()){
        std::cout<<"thread joined";
        t.detach();
    }
    std::thread p([&data,&queue](){
        while(true){
            data.addData(Parser::parseLatest(queue, Config::config.market_name));
        }
        
    });

    if(p.joinable()){
        std::cout <<"thread joined";
        p.join();
    }

    std::unique_ptr<Analyzer> ok = std::make_unique<MomentumAnalyzer>();

}

