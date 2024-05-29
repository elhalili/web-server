#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <string>
#include <unordered_map>

using std::string, std::unordered_map;

/**
 * @brief Represents an HTTP response.
 */
class HttpResponse
{
private:
    int status_code;                       ///< HTTP status code
    unordered_map<string, string> headers; ///< HTTP headers
    string body;                           ///< Response body

public:
    /**
     * @brief Construct a new HttpResponse object.
     */
    HttpResponse();

    /**
     * @brief Set the HTTP status code.
     *
     * @param code HTTP status code
     */
    void set_status_code(int code);

    /**
     * @brief Set an HTTP header.
     *
     * @param key Header key
     * @param value Header value
     */
    void set_header(const string &key, const string &value);

    /**
     * @brief Set the response body.
     *
     * @param body Response body
     */
    void set_body(const string &body);

    /**
     * @brief Get the response body.
     *
     * @return string Response body
     */
    string get_body() const;

    /**
     * @brief Convert the response to a string representation.
     *
     * @return string String representation of the response
     */
    string to_string() const;
};

#endif
