cmake_minimum_required(VERSION 3.1)

project(graph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    main.cpp
    src/Graph.cpp
    src/Node.cpp
    src/Vertex.cpp)

set(HEADERS
    include/Graph.h
    include/Node.h
    include/Vertex.h
    include/Utils.h)

add_executable(main ${SOURCES} ${HEADERS})
