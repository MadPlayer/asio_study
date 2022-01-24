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
  )



