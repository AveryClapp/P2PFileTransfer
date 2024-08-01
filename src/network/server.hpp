#ifndef SOCKET_H
#define SOCKET_H

#include "ClientConnection.hpp"


class Server {
    private:
        int serverFd;
        std::vector<std::unique_ptr<ClientConnection>> clientFds;
    public:
        Server();
        ~Server();

        bool bind(int port);
        bool listen(int backlog);
        std::unique_ptr<ClientConnection> accept();
        void closeClientConnection(int clientFd);

    private:

}


#endif