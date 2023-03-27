#include <iostream>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;
using ip::tcp;

int main() 
{
    boost::asio::io_service io_service;
    //также создаем сокет
    tcp::socket socket(io_service);
    //соединение
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 15000));
    // создаем сообщение
    const string msg = "Hello from Client!\n";
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg), error);
    if (!error) {
        cout << "Client sent hello message!" << endl;
    }
    else {
        cout << "send failed: " << error.message() << endl;
    }
    // получаем сообщение от сервера
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
    if (error && error != boost::asio::error::eof) {
        cout << "receive failed: " << error.message() << endl;
    }
    else {
        //прочитаем буфер уже средствами asio
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        cout << data << endl;
    }

    system("pause"); // подождем, почитаем...
    return 0;
}