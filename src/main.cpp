#include "./src/util/logging.hpp"
#include "./src/util/config.hpp"
#include "./src/network/server.hpp"
// CLI => # allowed clients, port
int main(int argc, char* argv) {

    Logger& logger = Logger::getInstance("log.txt", LogLevel::DEBUG, true);
    
    // Create a server socket 
    // Instantiate the app 
    // Until server socket needs to exit -> accept client connections and create a socket. Add socket to threadPool and coordinate with app. Use CLI object to handle input
    // Shutdown App on exit
    Server 



}