#include "marketdata.hpp"
#include "data.hpp"
#include "parser.hpp"
#include "../Queue/queue.hpp"

MarketData Parser::parse(Queue<std::string>& queue){

    std::string buffer = queue.pop();

    std::cout <<buffer <<"\n\n";
    return MarketData{};
}