#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <string>
#include <unordered_map>

using std::string, std::unordered_map;

/**
 * @brief Represents an HTTP request.
 */
class HttpRequest
{
private:
    unordered_map<string, string> headers; ///< HTTP headers
    string path;                           ///< Request path
    string body;                           ///< Request body
    bool next;                             ///< Flag indicating whether to continue processing after this request

public:
    unordered_map<string, string> data; ///< Additional data associated with the request

    /**
     * @brief Construct a new HttpRequest object.
     *
     * @param headers HTTP headers
     * @param path Request path
     * @param body Request body
     */
    HttpRequest(const unordered_map<string, string> &headers, const string &path, const string &body);

    /**
     * @brief Set the next flag.
     *
     * @param next Whether to continue processing after this request
     */
    void set_next(bool next);

    /**
     * @brief Get the HTTP headers.
     *
     * @return const unordered_map<string, string>& HTTP headers
     */
    const unordered_map<string, string> &get_headers() const;

    /**
     * @brief Get the request path.
     *
     * @return const string& Request path
     */
    const string &get_path() const;

    /**
     * @brief Get the request body.
     *
     * @return const string& Request body
     */
    const string &get_body() const;

    /**
     * @brief Check if the next flag is set.
     *
     * @return true if should continue processing, false otherwise
     */
    bool isNext();
};

#endif
