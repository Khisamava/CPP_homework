#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <ctime>
#include <mutex>


using boost::asio::ip::tcp;

int secret_number;
std::mutex cout_mutex;

void handle_client(tcp::socket socket) {
    try {
        auto endpoint = socket.remote_endpoint();
        std::string welcome = "Guess the number between 1 and 100\n";
        boost::asio::write(socket, boost::asio::buffer(welcome));

        std::time_t last_guess_time = 0;

        while (true) {
            char data[1024] = {0};
            boost::system::error_code error;
            size_t length = socket.read_some(boost::asio::buffer(data), error);

            if (error == boost::asio::error::eof || error) break;

            std::time_t current_time = std::time(nullptr);
            if (std::difftime(current_time, last_guess_time) < 10) {
                std::string wait_msg = "Wait 10 seconds before guessing again.\n";
                boost::asio::write(socket, boost::asio::buffer(wait_msg));
                continue;
            }

            int guess = std::atoi(data);
            std::string response;

            if (guess < secret_number) response = "Too low.\n";
            else if (guess > secret_number) response = "Too high.\n";
            else response = "Correct! You win!\n";

            boost::asio::write(socket, boost::asio::buffer(response));
            last_guess_time = current_time;

            if (guess == secret_number) break;
        }
    } catch (...) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cerr << "Client disconnected.\n";
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    secret_number = rand() % 100 + 1;
    std::cout << "Secret number: " << secret_number << std::endl;

    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

        std::cout << "Server is running on port 12345...\n";

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            std::thread(handle_client, std::move(socket)).detach();
        }
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
