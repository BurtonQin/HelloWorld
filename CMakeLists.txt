cmake_minimum_required(VERSION 3.1)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)

find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
include_directories("${PROJECT_SOURCE_DIR}/include")
add_subdirectory(lib)
#add_subdirectory(runtime)
#add_subdirectory(parser)
