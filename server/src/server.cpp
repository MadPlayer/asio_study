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


  try
    {
      tcp::acceptor acceptor(context, tcp::v4());

      acceptor.bind(ep);
      acceptor.listen();

      tcp::socket sock(context);

      acceptor.accept(sock);

    }
  catch (std::system_error &ec)
    {
      std::cerr << "Error(" << ec.code() << "): " << ec.what() << std::endl;
      return ec.code().value();
    }

  return 0;
}
