#include "server.h"
#include <cstddef>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>
#include <thread>
#include <iostream>

using std::runtime_error;

Server::Server(uint16_t port, size_t max_worker) : port(port), sem(max_worker)
{
    fd_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (fd_socket == -1)
        throw runtime_error("Can not create the socket");

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    socklen = sizeof(address);
}

void Server::bind_socket()
{
    if (bind(fd_socket, (struct sockaddr *)&address, socklen) < 0)
        throw runtime_error("Can not bind the socket");
}

void Server::start()
{
    bind_socket();
    if (listen(fd_socket, 3) < 0)
        throw runtime_error("Can not listen to the port");

    std::cout << "The server is running on " << this->port << std::endl;

    while (true)
    {
        int new_socket;
        if ((new_socket = accept(fd_socket, (struct sockaddr *)&address, &socklen)) < 0)
            throw runtime_error("Can not accept a new request");

        sem.wait();
        std::thread(&Server::handler, this, new_socket).detach();
    }
}
