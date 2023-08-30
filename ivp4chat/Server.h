#pragma once
#include "Socket.h"


#ifndef IVP4CHAT_SERVER_H
#define IVP4CHAT_SERVER_H


class Server {
public:
    Server(const char * ipAddress,const int port);
    ~Server();
    void listenForMessages();

private:
    Socket socket;


};


#endif //IVP4CHAT_SERVER_H
