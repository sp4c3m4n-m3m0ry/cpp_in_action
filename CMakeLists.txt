cmake_minimum_required(VERSION 3.27)

project(ExampleInAction)

add_executable(Calculator
    main.cpp
    parser.cpp
    scanner.cpp
    list.cpp
    functiontable.cpp
    symboltable.cpp
    htable.h)