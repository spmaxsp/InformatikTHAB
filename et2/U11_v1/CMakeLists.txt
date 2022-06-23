cmake_minimum_required(VERSION 3.0.0)
project(U11 VERSION 0.1.0)

add_executable(U11 main.c sortingHelperStructures.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
