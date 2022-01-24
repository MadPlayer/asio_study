cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(server_sources server.cpp)
list(TRANSFORM server_sources PREPEND "src/")

add_executable(server
  ${server_sources}
  )

target_link_libraries(server
  -lpthread)

target_include_directories(server PUBLIC
  ${ASIO_HEADER}
  "include/"
  "../include/"
  )
