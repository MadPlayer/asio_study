#include "asio.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <system_error>

using namespace asio;
using namespace asio::ip;

int main(int argc, char *argv[])
{
  io_context context;
  tcp::endpoint ep(address_v4::any(), 3333);
  tcp::acceptor socket(context);
  std::error_code ec;

  socket.open(tcp::v4(), ec);

  if (ec.value())
    {
      std::cerr
        << "Failed to open the acceptor socket!\n"
        << "Error code: " << ec.value()
        << ".\n " << ec.message() << std::endl;
      return ec.value();
    }

  return 0;
}
