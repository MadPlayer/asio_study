cmake_minimum_required(VERSION 3.10)

# set the project name
project(asio_study VERSION 0.1)


# =========================== client side ============================
set(client_sources client.cpp)
list(TRANSFORM client_sources PREPEND "src/client/")

add_executable(client
  "${client_sources}"
  )

target_link_libraries(client
  -lpthread)

target_include_directories(client PUBLIC
  "$ENV{ASIO_HEADER}"
  "include/"
  )


# =========================== server side ============================
# set(server_sources server.cpp)
# list(TRANSFORM server_sources PREPEND "src/server/")

# add_executable(server
#   ${server_sources}
#   )

# target_link_libraries(server
#   -lpthread)

# target_include_directories(server PUBLIC
#   "$ENV{ASIO_HEADER}"
#   "include/"
#   )



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
