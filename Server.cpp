#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <optional>

//класс одного соединения
class session : public std::enable_shared_from_this<session>
{
public:
    //конструктор по умолчанию, принимающий наш сокет
    session(boost::asio::ip::tcp::socket&& socket) : socket(std::move(socket)) {}

    //читаем данные из буфера, пока не встретим знак перевода строки
    void start()
    {
        boost::asio::async_read_until(socket, streambuf, '\n', [self = shared_from_this()](boost::system::error_code error, std::size_t bytes_transferred) { std::cout << std::istream(&self->streambuf).rdbuf(); });
    }

private:
    boost::asio::ip::tcp::socket socket;
    boost::asio::streambuf streambuf;
};

//класс сервера
class server
{
public:
    server (boost::asio::io_context& io_context, std::uint16_t port) : io_context(io_context), acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {}

    //начинаем принимать входящие подключения
    void async_accept()
    {
        auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_context);
        acceptor.async_accept(*socket, [&, socket](boost::system::error_code error) 
            {
                std::make_shared<session>(std::move(*socket))->start();
                async_accept();
            });
    }

private:
    boost::asio::io_context& io_context;
    boost::asio::ip::tcp::acceptor acceptor;
};

int main()
{
    boost::asio::io_context io_context;
    server srv(io_context, 15000); // создаем сервер и сокет на порту 15000
    srv.async_accept(); // запускаем асинхронно при каждой новой сессии
    io_context.run();
    return 0;
}