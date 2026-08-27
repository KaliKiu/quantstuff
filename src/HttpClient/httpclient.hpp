#pragma once


class HttpClient{
    private:
    int id;
    char* data;

    public:
    HttpClient(int id);
    HttpClient();
    ~HttpClient();


    void getData();
    int getId();
};