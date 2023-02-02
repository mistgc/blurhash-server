#ifndef HTTP_SERVER_H

#include "http.h"
#include <ctype.h>

typedef struct {
  const char *ip_addr;
  size_t ip_addr_len;
  uint16_t ip_port;
} Address;

Address *Address_new(const char *ip_addr, size_t ip_addr_len, uint16_t ip_port);
void Address_free(Address *self);

typedef struct {
  Address *ipv4_addr;
  uint8_t log_level;
} HttpServer;

HttpServer *HttpServer_new(char *ip_addr, size_t ip_addr_len, uint16_t ip_port,
                           uint8_t log_level);
void HttpServer_free(HttpServer *self);
void HttpServer_run(HttpServer *self);

static void HttpServer_on_request(http_s *request);
static void HttpServer_init_routes(http_s *request);
static void HttpServer_handle_blurhash(http_s *request);
static void HttpServer_handle_about(http_s *request);

#endif // !HTTP_SERVER_H
