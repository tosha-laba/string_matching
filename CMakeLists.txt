cmake_minimum_required(VERSION 3.0.0)
project(string_matching VERSION 0.1.0)

include(CTest)
enable_testing()

set(
    SOURCES

    src/string_matching/naive.hpp
    src/string_matching/kmp.hpp
    src/string_matching/rabin_karp.hpp
    src/string_matching/utils.hpp
    src/main.cpp
)

add_executable(string_matching ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
