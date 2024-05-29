#include "HttpRequest.h"

HttpRequest::HttpRequest(const unordered_map<string, string> &headers, const string &path, const string &body)
    : headers(headers), path(path), body(body), next(true) {}

void HttpRequest::set_next(bool next)
{
    this->next = next;
}

const unordered_map<string, string> &HttpRequest::get_headers() const
{
    return headers;
}

const string &HttpRequest::get_path() const
{
    return path;
}

const string &HttpRequest::get_body() const
{
    return body;
}

bool HttpRequest::isNext()
{
    return next;
}
