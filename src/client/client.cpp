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
  std::error_code ec;


  socket.open(tcp::v4(), ec);

  if (ec.value())
    {
      std::cerr << ec.value() << " " << ec.message() << std::endl;
      return ec.value();
    }

  return 0;
}
