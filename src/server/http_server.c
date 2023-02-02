#include "server/http_server.h"
#include "blurhash/encode.h"
#include "fio.h"
#include "fiobj_hash.h"
#include "fiobj_json.h"
#include "fiobject.h"
#include "http.h"
#include "stb/stb_image.h"
#include <stdio.h>
#include <stdlib.h>

Address *Address_new(const char *ip_addr, size_t ip_addr_len,
                     uint16_t ip_port) {
  Address *self = malloc(sizeof(*self));
  *self = (Address){
      .ip_addr = ip_addr,
      .ip_addr_len = ip_addr_len,
      .ip_port = ip_port,
  };
  return self;
}

void Address_free(Address *self) {
  free(self);
  self = NULL;
}

HttpServer *HttpServer_new(char *ip_addr, size_t ip_addr_len, uint16_t ip_port,
                           uint8_t log_level) {
  HttpServer *self = malloc(sizeof(*self));
  Address *ipv4_addr = Address_new(ip_addr, ip_addr_len, ip_port);

  *self = (HttpServer){
      .ipv4_addr = ipv4_addr,
      .log_level = log_level,
  };

  return self;
}

void HttpServer_free(HttpServer *self) {
  Address_free(self->ipv4_addr);

  free(self);
  self = NULL;
}

void HttpServer_run(HttpServer *self) {
  if (!self)
    return;
  char port[16];
  sprintf(port, "%d", self->ipv4_addr->ip_port);
  http_listen(port, NULL, .on_request = HttpServer_on_request, .log = 1);
  fio_start(.threads = 1);
}

static void HttpServer_on_request(http_s *request) {
  HttpServer_init_routes(request);
}

static void HttpServer_init_routes(http_s *request) {
  fio_str_info_s path = fiobj_obj2cstr(request->path);

  if (!strcmp(path.data, "/blurhash")) {
    HttpServer_handle_blurhash(request);
    return;
  }
  if (!strcmp(path.data, "/about")) {
    HttpServer_handle_about(request);
    return;
  };
}

static void HttpServer_handle_blurhash(http_s *request) {
  char *method = fiobj_obj2cstr(request->method).data;
  if (!strcmp(method, "POST")) {
    http_parse_query(request);
    http_parse_body(request);

    FIOBJ data_key = fiobj_str_new("data", 4);
    FIOBJ file_hash_wrapper = fiobj_hash_get(request->params, data_key);
    fio_str_info_s file_data =
        fiobj_obj2cstr(fiobj_hash_get(file_hash_wrapper, data_key));

    FILE *tmp = tmpfile();
    if (!tmp) {
      printf("Create tmpfile failed...\n");
      fiobj_free(data_key);
      fiobj_free(file_hash_wrapper);
      return;
    }

    fwrite(file_data.data, 1, file_data.len, tmp);
    rewind(tmp);
    int x, y, n;
    uint8_t *img_data = stbi_load_from_file(tmp, &x, &y, &n, 3);
    const char *blurhash = blurHashForPixels(3, 4, x, y, img_data, x * 3);
    char json_data[256];
    sprintf(json_data, "{\"blurhash\":\"%s\"}\n", blurhash);
    http_send_body(request, json_data, strlen(json_data));

    fiobj_free(data_key);
    fiobj_free(file_hash_wrapper);

    return;
  }
  printf("Method: %s\n", method);
}

static void HttpServer_handle_about(http_s *request) {
  http_send_body(request, "This is about page...\n", 22);
}
