#include <iostream>
#include <curl/curl.h>
#include <thread>

#include "HttpClient/httpclient.hpp"
#include "Config/config.hpp"
#include "Queue/queue.hpp"
#include "Data/marketdata.hpp"
#include "Data/data.hpp"
#include "Analyze/analyzer.hpp"
#include "Analyze/momentumanalyzer.hpp"

static constexpr const char* CONFIG_FILE_DIR =  "../data/config.json";

int main(){
    Config::loadconfig(CONFIG_FILE_DIR);
    Queue<std::string> queue;

    HttpClient meow();
    Data data();
    std::unique_ptr<Analyzer> meow = std::make_unique<MomentumAnalyzer>();

}

