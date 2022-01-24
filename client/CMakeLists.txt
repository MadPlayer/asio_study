set(client_sources client.cpp)
list(TRANSFORM client_sources PREPEND "src/")

add_executable(client
  "${client_sources}"
  )

target_link_libraries(client
  -lpthread)

target_include_directories(client PUBLIC
  ${ASIO_HEADER}
  "include/"
  )
