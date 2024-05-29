#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include "HttpRequest.h"
#include "HttpResponse.h"
#include "server.h"
#include <cstdint>
#include <unordered_map>
#include <vector>

#define MAX_WORKER 10

/**
 * @brief Supported http verbs
 */
enum HTTP_VERB
{
    GET
};

/**
 * @brief Represents an HTTP server.
 */
class HttpServer : public Server
{
private:
    std::unordered_map<std::string, std::vector<bool (*)(HttpRequest &, HttpResponse &)>> routes; ///< Routes and their handlers

    /**
     * @brief Override of the handler method from the base class.
     *
     * @param new_socket Socket for the new connection
     */
    void handler(int new_socket) override;

public:
    /**
     * @brief Construct a new HttpServer object.
     *
     * @param port Port number for the server
     * @param max_worker Maximum number of worker threads
     */
    HttpServer(uint16_t port, size_t max_worker = MAX_WORKER);

    /**
     * @brief Add a route with a handler to the server.
     *
     * @param verb HTTP verb (GET or POST)
     * @param path Path for the route
     * @param handler Function pointer to the route handler
     */
    void add_route(HTTP_VERB verb, const std::string &path, bool (*handler)(HttpRequest &, HttpResponse &));
};

#endif
