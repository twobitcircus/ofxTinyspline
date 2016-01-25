cmake_minimum_required(VERSION 2.8)

file(GLOB SRC "*.c")

add_executable(AllCTests ${SRC})
target_link_libraries(AllCTests LINK_PUBLIC tinyspline_static)
