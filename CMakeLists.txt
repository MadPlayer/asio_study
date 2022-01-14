cmake_minimum_required(VERSION 3.10)

# set the project name
project(asio_study VERSION 0.1)

# add the executable
add_executable(asio_study main.cpp)


target_include_directories(asio_study PUBLIC
  "$ENV{ASIO_HEADER}"
  )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
