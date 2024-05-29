#ifndef SERVER_H
#define SERVER_H

#include <cstddef>
#include <netinet/in.h>
#include <sys/socket.h>
#include "semaphore.h"

/**
 * @brief Base class for server implementations.
 */
class Server
{
private:
    uint16_t port;       ///< Port number
    sockaddr_in address; ///< Socket address
    int fd_socket;       ///< Socket file descriptor
    socklen_t socklen;   ///< Length of socket address structure

public:
    /**
     * @brief Construct a new Server object.
     *
     * @param port Port number for the server
     * @param max_worker Maximum number of worker threads
     */
    Server(uint16_t port, size_t max_worker);

    /**
     * @brief Start the server.
     */
    void start();

protected:
    /**
     * @brief Bind the socket to the address.
     */
    void bind_socket();

    /**
     * @brief Handler method for processing incoming connections.
     *
     * @param new_socket Socket for the new connection
     */
    virtual void handler(int new_socket) = 0;

    Semaphore sem; ///< Semaphore for controlling the number of worker threads
};

#endif
