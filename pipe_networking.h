#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>

#ifndef NETWORKING_H
#define NETWORKING_H
#define ACK "HOLA"
#define WKP "mario"

#define HANDSHAKE_BUFFER_SIZE 10
#define BUFFER_SIZE 1000

//for forking server
int server_setup();
int server_connect(int sock);

int client_setup();

#endif
