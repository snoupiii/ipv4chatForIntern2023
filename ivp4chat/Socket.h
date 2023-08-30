#pragma once

#include <netinet/in.h>

class Socket{
public:
    Socket();
    ~Socket();

    bool bindSocket(const char* ipAddress, const int port);
    bool setBroadcast();
    int sendBroadcast(const int port, const char* data, const size_t length);

    int receiveFrom(char* buffer, const size_t bufferSize, sockaddr_in* fromAddr);


private:
    int socketFd;
    sockaddr_in address;
};



#ifndef IVP4CHAT_SOCKET_H
#define IVP4CHAT_SOCKET_H

#endif //IVP4CHAT_SOCKET_H
