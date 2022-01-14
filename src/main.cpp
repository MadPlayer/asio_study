#include "asio.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <system_error>

using namespace asio;
using namespace asio::ip;

int main(int argc, char *argv[])
{
  std::string server_name = "google.com";
  io_context context;
  executor_work_guard<io_context::executor_type> work_guard = make_work_guard(context);
  tcp::resolver::query query(server_name, "http");
  tcp::resolver resolver(context);
  tcp::socket socket(context);
  std::thread worker([&context](){ context.run(); });

  connect(socket, resolver.resolve(query));

  if (socket.is_open())
    {
      std::cout << "done!\n";
      socket.close();
    }
  context.stop();
  worker.join();

  return 0;
}
