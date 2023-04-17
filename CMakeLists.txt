cmake_minimum_required(VERSION 3.24)
project(Clothes_Shop)

set(CMAKE_CXX_STANDARD 23)

add_executable(Clothes_Shop main.cpp persons/person.h persons/person.cpp persons/customer.h persons/customer.cpp persons/employee.h persons/employee.cpp)
