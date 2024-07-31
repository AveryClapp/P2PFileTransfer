#include "logging.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void test_logger() {
    // Create a logger
    Logger logger("test_log.txt", LogLevel::DEBUG, true);

    // Test different log levels
    logger.log_message("This is a debug message", LogLevel::DEBUG);
    logger.log_message("This is an info message", LogLevel::INFO);
    logger.log_message("This is a warning message", LogLevel::WARNING);
    logger.log_message("This is an error message", LogLevel::ERROR);
    logger.log_message("This is a critical message", LogLevel::CRITICAL);

    // Test changing log level
    logger.set_log_level(LogLevel::WARNING);
    logger.log_message("This debug message should not appear", LogLevel::DEBUG);
    logger.log_message("This info message should not appear", LogLevel::INFO);
    logger.log_message("This warning message should appear", LogLevel::WARNING);

    // Test multiple log messages in quick succession
    for (int i = 0; i < 5; ++i) {
        logger.log_message("Rapid log message " + std::to_string(i), LogLevel::ERROR);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    try {
        test_logger();
        std::cout << "Logging test completed successfully. Check test_log.txt for results." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}