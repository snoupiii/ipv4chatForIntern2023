#include "Client.h"
#include <iostream>

Client::Client(const int port, const std::string& nickname) : socket(), port(port), nickname(nickname) {
    socket.setBroadcast();
}

void Client::SendMessage() {
    std::string message;
    std::getline(std::cin, message);
    if (message.size() > 1000) {
        std::cerr << "Message too long!" << std::endl;
        return;
    }

    std::string fullMessage = nickname + ": " + message;
    socket.sendBroadcast(port, fullMessage.c_str(), fullMessage.size());
}
