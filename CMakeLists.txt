cmake_minimum_required(VERSION 4.1)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()
add_executable(prime prime.cpp)
target_link_libraries(prime ${wxWidgets_LIBRARIES})