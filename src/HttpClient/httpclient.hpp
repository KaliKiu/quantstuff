#pragma once

#include "../Queue/queue.hpp"

class HttpClient{
    private:
    std::string buffer;
    std::uint32_t count;

    public:
    HttpClient();
    ~HttpClient();

    void getData();
    void pushData(Queue<std::string>& queue);
};