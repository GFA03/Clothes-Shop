cmake_minimum_required(VERSION 3.24)
project(Clothes_Shop)

set(CMAKE_CXX_STANDARD 23)

add_executable(Clothes_Shop main.cpp persons/person.h persons/person.cpp persons/customer.h persons/customer.cpp persons/employee.h persons/employee.cpp shop/product.h shop/product.cpp shop/shirt.h shop/shirt.cpp shop/pants.h shop/pants.cpp shop/jacket.h shop/jacket.cpp shop/pyjama.h shop/pyjama.cpp menu.h menu.cpp IOInterface.h)
