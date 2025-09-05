cmake_minimum_required(VERSION 3.5...3.31)

add_subdirectory(lib/wxWidgets)
add_executable(prime prime.cpp)
target_link_libraries(prime wx::net wx::core wx::base)