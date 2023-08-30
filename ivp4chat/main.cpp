#include "Server.h"
#include "Client.h"
#include <iostream>
#include <pthread.h>

void * serverThreadFunction(void* arg){
    Server* server = static_cast<Server*>(arg);
    server->listenForMessages();
    return nullptr;

}

void * clientThreadFunction(void* arg){
    Client*client = static_cast<Client*>(arg);
    while (true){
        client->SendMessage();
    }
    return nullptr;

}

int main(int argc,char* argv[]){
    if(argc!=3){
        std::cerr <<"Usage: "  <<argv[0]<<" <IP Address>" <<std::endl;
        return 1;
    }

    const char * ipAddress = argv[1];
    int port = std::stoi(argv[2]);

    std::string nickname;
    std::cout<<"Write your nickname please <3";
    std::cin>> nickname;
    std::cin.ignore();

    Server server(ipAddress,port);
    Client client(port,nickname);

    pthread_t serverThread;
    pthread_t clientThread;

    pthread_create(&serverThread, nullptr, serverThreadFunction, &server);
    pthread_create(&clientThread, nullptr, clientThreadFunction, &client);

    pthread_join(serverThread, nullptr);
    pthread_join(clientThread, nullptr);

    return 0;


}