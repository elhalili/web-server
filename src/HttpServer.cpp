#include "HttpServer.h"
#include <unistd.h>
#include <sstream>

HttpServer::HttpServer(uint16_t port, size_t max_worker) : Server(port, max_worker) {}

void HttpServer::add_route(HTTP_VERB verb, const std::string &path, bool (*handler)(HttpRequest &, HttpResponse &))
{
    routes[path].push_back(handler);
}

void HttpServer::handler(int new_socket)
{
    char buffer[30000] = {0};
    read(new_socket, buffer, 30000);

    // Parse the HTTP request
    std::stringstream ss(buffer);
    std::string method, path, http_version;
    ss >> method >> path >> http_version;

    // Extract headers and body
    std::unordered_map<std::string, std::string> headers;
    std::string line;
    while (std::getline(ss, line) && line != "\r")
    {
        size_t pos = line.find(": ");
        if (pos != std::string::npos)
        {
            std::string header_name = line.substr(0, pos);
            std::string header_value = line.substr(pos + 2);
            headers[header_name] = header_value;
        }
    }

    std::string body;
    while (std::getline(ss, line))
    {
        body += line + "\n";
    }

    // Construct HttpRequest object
    HttpRequest req(headers, path, body);
    HttpResponse res;

    // Currently only handles GET requests
    if (method == "GET" && routes.find(path) != routes.end())
    {
        for (auto &handler : routes[path])
        {
            // Middlewares
            if (!handler(req, res))
                break;
        }

        write(new_socket, res.to_string().c_str(), res.to_string().size());
        close(new_socket);

        sem.notify();

        return;
    }

    // Not found response
    std::string response = "HTTP/1.1 404 Not Found\nContent-Type: text/plain\nContent-Length: 12\n\nNot found";
    write(new_socket, response.c_str(), response.size());
    close(new_socket);
    sem.notify();
}
