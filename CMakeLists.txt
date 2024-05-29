cmake_minimum_required(VERSION 3.5)
project(server)

set(CMAKE_CXX_STANDARD 11)

# Add your source files
set(SOURCE_FILES 
    main.cpp
    src/HttpRequest.cpp
    src/HttpResponse.cpp
    src/HttpServer.cpp
    src/server.cpp
    src/semaphore.cpp
)

# Add header files
set(HEADER_FILES 
    src/HttpRequest.h
    src/HttpResponse.h
    src/HttpServer.h
    src/server.h
    src/semaphore.h
)


# Add the executable
add_executable(server ${SOURCE_FILES} ${HEADER_FILES})
