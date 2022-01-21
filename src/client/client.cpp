#include "asio.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <system_error>

using namespace asio;
using namespace asio::ip;

int main(int argc, char *argv[])
{
  std::string address = "127.0.0.1";
  io_context context;
  tcp::endpoint ep(make_address(address), 80);
  tcp::socket socket(context);



  if (socket.is_open())
    {
      std::cout << "done!\n";
      socket.close();
    }

  socket.send(buffer(address.c_str(), address.length()));
  socket.close();

  return 0;
}
