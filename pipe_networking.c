#include "pipe_networking.h"

int server_setup() {
  struct addrinfo *hints, *results;
  hints = calloc(1, sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM;
  hints->ai_flags = AI_PASSIVE;
  getaddrinfo(NULL, "9845", hints, &results);

  int sock = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  bind(sock, results->ai_addr, results->ai_addrlen);
  printf("Waiting for a connection ...\n");

  listen(sock, 10);

  free(hints);
  freeaddrinfo(results);

  return sock;
}

int server_connect(int sock) {
  int client_socket;
  socklen_t sock_size;
  struct sockaddr_storage client_address;
  sock_size = sizeof(client_address);
  client_socket = accept(sock, (struct sockaddr *)&client_address, &sock_size);

  return client_socket;
}

int client_setup() {
  struct addrinfo *hints, *results;
  hints = calloc(1, sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM;
  getaddrinfo(NULL, "9845", hints, &results);

  int sock = socket(results->ai_family, results->ai_socktype, results->ai_protocol);

  connect(sock, results->ai_addr, results->ai_addrlen);
  free(hints);
  freeaddrinfo(results);
  return sock;
}
