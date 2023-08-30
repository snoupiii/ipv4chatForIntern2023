#include "Server.h"
#include <iostream>
#include <pthread.h>
#include <cstring>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/ioctl.h>



using namespace std;

Server::Server(const char *ipAddress, const int port) {
    socket.bindSocket(ipAddress,port);
    socket.setBroadcast();

}

Server::~Server() {}

void Server::listenForMessages() {
    char buffer[1024];
    sockaddr_in fromAddr;

    while(true){
        int bytesReceived = socket.receiveFrom(buffer,sizeof (buffer), &fromAddr);
        if (bytesReceived > 0){
            buffer[bytesReceived]  = '\0';
            std::cout <<inet_ntoa(fromAddr.sin_addr)<< ": " <<buffer<<std::endl;
        }
    }
}