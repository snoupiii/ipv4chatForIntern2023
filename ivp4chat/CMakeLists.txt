cmake_minimum_required(VERSION 3.10)

project(ipv4chat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ipv4chat
        main.cpp
        Server.cpp
        Socket.cpp
        Client.cpp
)

target_link_libraries(ipv4chat pthread)
