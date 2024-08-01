#include "server.hpp";
#include "../util/logger.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

Server::Server() {
    serverFd = socket(AF_INET, SOCK_STREAM, 0);\
    if (serverFd < 0) {
        Logger::getInstance.log_message("Failed to create server socket", Logger::ERROR);
        exit(EXIT_FAILURE);
    }

}

Server::~Server() {
    if (serverFd > 0) {
        close(serverFd);
    }
}

Server::bind(int port) {
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (::bind(serverFd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        Logger::getInstance().log_message("Failed to bind server socket", Logger::ERROR);
        return false;
    }

    Logger::getInstance().log_message("Server socket bound successfully", Logger::INFO);
    return true;
}

Server::listen(int backlog) {
    if (::listen(serverFd, backlog) < 0) {
        Logger::getInstance().log_message("Failed to listen on server socket", Logger::ERROR);
        return false;
    }

    Logger::getInstance().log_message("Server is now listening", Logger::INFO);
    return true;
}

Server::accept() {
    struct sockaddr_in clientAddress;
    socklen_t addrlen = sizeof(clientAddress);

    int clientFd = ::accept(serverFd, (struct sockaddr *)&clientAddress, &addrlen);
    if (clientFd < 0) {
        Logger::getInstance().log_message("Failed to accept client connection", Logger::ERROR);
        return nullptr;
    }

    auto clientConn = std::make_unique<ClientConnection>(clientFd, clientAddress);
    clientFds.push_back(std::move(clientConn));

    Logger::getInstance().log_message("New client connection accepted", Logger::INFO);
    return std::move(clientFds.back());
}