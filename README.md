Here's the formatted README.md:

# Multithreading Web Server in C++

This project is a multithreading HTTP web server implemented in C++.

## Table of Contents

- [Introduction](##introduction)
- [Dependencies](##dependencies)
- [Installation](##installation)
- [Usage](##usage)
- [Examples](##examples)
- [Contributing](##contributing)
- [License](##license)

## Introduction

The Multithreading Web Server in C++ is designed to handle concurrent HTTP requests efficiently. It allows developers to create custom routes and handlers for different HTTP methods, for building RESTful APIs, web applications, and more.

## Dependencies

This project relies on the following essential components:

- **Thread API**: Utilized for managing multithreading tasks efficiently. (`<thread>` header)
- **Socket API**: Employed for networking functionalities, particularly in establishing and managing socket connections for HTTP communication. (`<sys/socket.h>`, `<netinet/in.h>` headers)

## Installation

### Installing the demo the Multithreading Web Server in C++

1. Clone the repository:

    ```bash
    git clone https://github.com/elhalili/web-server.git
    ```

2. Build the library using CMake:

    ```bash
    cd multithreading-web-server-cpp
    mkdir build
    cd build
    cmake ..
    make
    ./server
    ```

### Adding the Library to Your Project

1. Clone the repository of your project:

    ```bash
    git clone https://github.com/elhalili/web-server.git
    cd your_project
    ```

2. Copy the src directory of the Multithreading Web Server into your project directory.

## Examples

A basic example:

```cpp
HttpServer server(8080); // or mention the max worker threads
// HttpServer server(8080, 20); 

// Add routes and their corresponding handler functions
server.add_route(GET, "/", [](HttpRequest &req, HttpResponse &res)
                 {
    res.set_header("Content-Type", "text/html");
    res.set_body("<h1>Hello, World!</h1>"); 
    return false; });

server.add_route(GET, "/about", [](HttpRequest &req, HttpResponse &res)
                 {
    res.set_header("Content-Type", "text/html");
    res.set_body("<h2>About Us</h2><p>We are a demo server.</p>");
    return false; });

server.add_route(GET, "/middleware", [](HttpRequest &req, HttpResponse &res)
                 {
                     res.set_header("Content-Type", "application/json");
                     res.set_body("{\"data\": ");
                     req.data["mdw 2"] = "I am middleware 2";
                     // return false;
return true; });

server.add_route(GET, "/middleware", [](HttpRequest &req, HttpResponse &res)
                 { res.set_body(res.get_body() + "\"" + req.data["mdw 2"] + "\"}"); 
                 return false; });

try
{
    // Start the server
    server.start();
}
catch (const std::exception &e)
{
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
}
```

## Contributing

We welcome contributions from the community to improve the Multithreading Web Server in C++ project. If you'd like to contribute, please follow these guidelines:

- **Bug Reports**: If you encounter a bug, please open an issue on GitHub with a detailed description of the problem, including steps to reproduce it.
- **Feature Requests**: If you have a feature request or an idea for improvement, please open an issue on GitHub to discuss it.
- **Pull Requests**: If you'd like to contribute code, please fork the repository, create a new branch, commit your changes, and then open a pull request on GitHub.

We appreciate your contributions in making this project better for everyone!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

