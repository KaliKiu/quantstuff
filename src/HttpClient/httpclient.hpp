#pragma once

#include "../Queue/queue.hpp"

class HttpClient{
    private:
    std::string buffer;

    public:
    HttpClient();
    ~HttpClient();

    void getData();
    void pushData(Queue<std::string>& queue);
};