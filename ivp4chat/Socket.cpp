#include "Socket.h"
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <netinet/in.h>

Socket::Socket() {
    socketFd = socket(AF_INET, SOCK_DGRAM,0);

}

Socket::~Socket(){
    close(socketFd);

}

bool Socket::bindSocket(const char *ipAddress, const int port) {
    memset(&address,0,sizeof(address) );
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ipAddress);
    address.sin_port= htons(port);
    return bind(socketFd,(struct sockaddr*)&address,sizeof(address) ) == 0;
}

bool Socket::setBroadcast() {
    int broadCastOn = 1;
    return setsockopt(socketFd,SOL_SOCKET,SO_BROADCAST,&broadCastOn, sizeof(broadCastOn)) == 0;
}

int Socket::sendBroadcast(const int port, const char *data, const size_t length) {
    sockaddr_in broadcastAddr;
    memset(&broadcastAddr,0,sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    broadcastAddr.sin_port= htons(port);
    return sendto(socketFd,data,length,0, (struct sockaddr*)&broadcastAddr,sizeof(broadcastAddr) );
}

int Socket::receiveFrom(char *buffer, const size_t bufferSize, sockaddr_in *fromAddr) {
    socklen_t addrSize = sizeof (*fromAddr);
    return recvfrom(socketFd,buffer, bufferSize, 0,(struct sockaddr*)fromAddr,&addrSize);

}

