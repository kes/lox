
cmake_minimum_required(VERSION 3.16..3.24)
project(lox VERSION 1.0)
   
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED Yes)

                                                            
## we will be testing
include(CTest)

## libraries for the app
#add_subdirectory(src/)
#add_subdirectory(src)
#include_directories(src/scanner)
## testing --external is gtest
#add_subdirectory(submods)
## the actual tests
#add_subdirectory(tests)

## the app itself
#add_executable(Compiler src/compiler.cpp $<TARGET_OBJECTS:Scanner.o>)
#add_subdirectory(scanner)

add_executable(lox src/lox.cpp src/scanner/Scanner.cpp src/scanner/Token.cpp) 

target_include_directories(lox PUBLIC 
    "${PROJECT_BINARY_DIR/src}"
    "${PROJECT_SOURCE_DIR}/src/scanner")
#target_link_libraries(Compiler PUBLIC Scanner) 

