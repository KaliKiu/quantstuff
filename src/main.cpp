#include <iostream>
#include <curl/curl.h>
#include "getdata.cpp"

int main(){
    int a = 2;
    DataObj meow(2);
    
    std::cout<< meow.getId();
    meow.pullData();
}

