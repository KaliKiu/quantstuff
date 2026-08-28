cmake_minimum_required(VERSION 3.23)
project(meow)
set(CMAKE_CXX_STANDARD 17)
find_package( CURL REQUIRED )

add_executable(meow 
                src/main.cpp 
                src/HttpClient/httpclient.cpp
                src/Analyze/momentumanalyzer.cpp
                src/Data/parser.cpp 
                src/Data/data.cpp
                src/config.cpp)
target_link_libraries(meow curl CURL::libcurl )
