#include "pipe_networking.h"

int main() {
  int socket = server_setup();
  int client_socket;

  while(1) {
    client_socket = server_connect(socket);
    int f = fork();

    if(!f) {
      while(1) {
        char temp[100];
        read(client_socket, temp, sizeof(temp));
        if(strcmp(temp, "exit") == 0 || strcmp(temp, "Exit") == 0) {
          printf("Goodbye. (Please press Ctrl+C on all windows.)\n");
          exit(0);
        }
        printf("Processing string ...\n");
        int i = 0;
        while(temp[i]) {
          if(temp[i] >= 'a' && temp[i] <= 'z') {
            temp[i] = temp[i] - 32;
          }
          i++;
        }
        write(client_socket, temp, sizeof(temp));
      }
      return 0;
    }
  }
}
