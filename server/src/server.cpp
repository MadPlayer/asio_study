#include "asio.hpp"
#include <iostream>
#include <string>
#include <system_error>
#include <array>

using namespace asio;
using namespace asio::ip;

int main(int argc, char *argv[])
{
  tcp::endpoint ep(address_v4::any(), 3333);

  try
    {
      io_context context;
      tcp::acceptor acceptor(context, tcp::v4());

      acceptor.bind(ep);
      acceptor.listen();

      while (true)
        {
          io_context io;
          tcp::socket sock(io);
          acceptor.accept(sock);
          std::cout << "accept\n";
          streambuf buf;
          read_until(sock, buf, '\n');
          std::string msg;
          std::istream input(&buf);

          std::getline(input, msg);
          std::cout << msg << std::endl;
        }
      acceptor.close();
      std::cout << "closed\n";
    }
  catch (std::system_error &ec)
    {
      std::cerr << "Error(" << ec.code() << "): " << ec.what() << std::endl;
      return ec.code().value();
    }

  return 0;
}
