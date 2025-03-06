cmake_minimum_required(VERSION 3.10.0)
project(data-structure VERSION 0.1.0 LANGUAGES C)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(TOP_DIR ${CMAKE_CURRENT_LIST_DIR}/)

add_subdirectory(${TOP_DIR}/linear_list)
add_subdirectory(${TOP_DIR}/tree)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE linear_list tree)
target_include_directories(${PROJECT_NAME} PRIVATE ${TOP_DIR}/linear_list ${TOP_DIR}/tree)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
