#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>  // для std::atoi
#include <ctime>    // для std::time

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "12345");
        tcp::socket socket(io_context);

        boost::asio::connect(socket, endpoints);

        char data[1024] = {0};
        std::string user_input;
        
        // Приветственное сообщение от сервера
        size_t length = socket.read_some(boost::asio::buffer(data));
        std::cout << "Server: " << data << std::endl;

        while (true) {
            std::cout << "Enter your guess (1-100): ";
            std::getline(std::cin, user_input);

            if (user_input.empty()) {
                std::cout << "Please enter a number!" << std::endl;
                continue;
            }

            // Отправка данных (число) на сервер
            boost::asio::write(socket, boost::asio::buffer(user_input));

            // Чтение ответа от сервера
            length = socket.read_some(boost::asio::buffer(data));
            std::cout << "Server: " << data << std::endl;

            // Проверка на успех (если число угадано)
            if (std::string(data).find("Correct") != std::string::npos) {
                std::cout << "You guessed the number correctly!" << std::endl;
                break;
            }
        }

        socket.close();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
