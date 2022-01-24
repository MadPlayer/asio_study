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
  tcp::endpoint ep(make_address(address), 3333);


  try
    {
      tcp::socket socket(context, tcp::v4());

      socket.connect(ep);

    }
  catch (std::system_error &ec)
    {
      std::cerr << "Error(" << ec.code() << "): " << ec.what() << std::endl;
      return ec.code().value();
    }


  return 0;
}
