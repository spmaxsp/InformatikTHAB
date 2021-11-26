cmake_minimum_required(VERSION 3.0.0)
project(U5_v1 VERSION 0.1.0)

add_executable(U5_v1 main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
