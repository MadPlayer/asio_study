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
  tcp::socket socket(context);


  return 0;
}
