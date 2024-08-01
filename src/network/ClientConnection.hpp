#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

class ClientConnection {
    private:
        int clientFd;
        std::string ipAddress;
        int port;
    public:
        ClientConnection(int fd, const sockaddr_in& clientAddress);
        ~ClientConnection();

        // Disable copy constructor and assignment operator
        ClientConnection(const ClientConnection&) = delete;
        ClientConnection& operator=(const ClientConnection&) = delete;

        // Enable move constructor and assignment operator
        ClientConnection(ClientConnection&& other) noexcept;
        ClientConnection& operator=(ClientConnection&& other) noexcept;


        bool sendData(const char* data, size_t length);
        int receiveData(char* buffer, size_t length);
        void close();

        int getFd() const { return clientFd; }
        std::string getIpAddress() const { return ipAddress; }
        int getPort() const { return port; }
}


#endif