cmake_minimum_required(VERSION 3.10)

# set the project name
project(asio_study VERSION 0.1)

set(target_sources main.cpp)
list(TRANSFORM target_sources PREPEND "src/")


# add the executable
add_executable(asio_study
  "${target_sources}"
  )

target_link_libraries(asio_study
  -lpthread)


target_include_directories(asio_study PUBLIC
  "$ENV{ASIO_HEADER}"
  "include/"
  )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
