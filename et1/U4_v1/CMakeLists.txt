cmake_minimum_required(VERSION 3.0.0)
project(U4 VERSION 0.1.0)


add_executable(U4 src/main.c src/geomittel.c)

target_link_libraries(U4 PRIVATE m)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
