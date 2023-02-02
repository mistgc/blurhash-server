#include "server/http_server.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Hello blurhash-server-v0.1 ❤️ \n");

  HttpServer *server = HttpServer_new("localhost", 9, 3000, 1);
  HttpServer_run(server);

  return EXIT_SUCCESS;
}
