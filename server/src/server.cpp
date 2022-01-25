#include "asio.hpp"
#include <iostream>
#include <string>
#include <system_error>
#include <array>
#include <memory>

using namespace asio;
using namespace asio::ip;

thread_pool pool(10);

void work(tcp::socket* sock)
{
  streambuf buf;
  read_until(*sock, buf, '\n');
  std::string msg;
  std::istream input(&buf);

  std::getline(input, msg);
  std::cout << msg << std::endl;
}

struct safe_socket
{
  std::unique_ptr<io_context> io_ptr;
  std::unique_ptr<tcp::socket> socket_ptr;

  safe_socket():
    io_ptr(std::make_unique<io_context>()),
    socket_ptr(std::make_unique<tcp::socket>(*io_ptr)) {}

  safe_socket(safe_socket&& s)
  {
    io_ptr = std::move(s.io_ptr);
    socket_ptr = std::move(s.socket_ptr);
  }

  tcp::socket &
  get_socket()
  {
    return *socket_ptr;
  }
};


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
          safe_socket s;
          acceptor.accept(s.get_socket());
          std::cout << "accept\n";

          asio::post(pool, [socket = std::move(s)](){
            work(socket.socket_ptr.get());
          });
        }

      acceptor.close();
      std::cout << "closed\n";
    }
  catch (std::system_error &ec)
    {
      std::cerr << "Error(" << ec.code() << "): " << ec.what() << std::endl;
      return ec.code().value();
    }

  pool.stop();
  pool.join();

  return 0;
}
