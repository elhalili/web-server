#include "HttpResponse.h"

HttpResponse::HttpResponse() : status_code(200) {}

void HttpResponse::set_status_code(int code)
{
    status_code = code;
}

void HttpResponse::set_header(const string &key, const string &value)
{
    headers[key] = value;
}

void HttpResponse::set_body(const string &body)
{
    this->body = body;
}

string HttpResponse::get_body() const
{
    return body;
}

string HttpResponse::to_string() const
{
    string response = "HTTP/1.1 " + std::to_string(status_code) + " OK\n";
    for (const auto &header : headers)
    {
        response += header.first + ": " + header.second + "\n";
    }
    response += "\n" + body;
    return response;
}
