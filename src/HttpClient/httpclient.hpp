#pragma once


class HttpClient{
    private:
    int id;
    char* data;

    public:
    HttpClient();
    ~HttpClient();

    std::string getData();
    void pushData();
};