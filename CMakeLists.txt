cmake_minimum_required(VERSION 3.10)

# set the project name
project(asio_study VERSION 0.1)

add_subdirectory(client)
add_subdirectory(server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
