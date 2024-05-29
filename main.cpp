#include "src/HttpServer.h"
#include <iostream>

int main()
{
    HttpServer server(8080);

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

    return 0;
}
