#pragma once
#include "Socket.h"
#include <string>


#ifndef IVP4CHAT_CLIENT_H
#define IVP4CHAT_CLIENT_H


class Client {
public:
    Client(const int port, const std::string&nickname);
    void SendMessage();
private:
    Socket socket;
    int port;
    std::string nickname;

};


#endif //IVP4CHAT_CLIENT_H
