#include "./util/logging.hpp"



int main() {
    Logger& logger = logger.getInstance("log.txt", LogLevel::DEBUG, true);
    logger.log_message("Test send message in main", LogLevel::DEBUG);
}