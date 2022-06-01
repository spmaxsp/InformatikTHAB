cmake_minimum_required(VERSION 3.0.0)
project(U9 VERSION 0.1.0)

add_executable(U9 main.c)

target_link_libraries(U9 PRIVATE m)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
