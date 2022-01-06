#include "pipe_networking.h"


int main() {
  int file = client_setup();
  char input[100];

  while(1) {
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    if(strcmp(input, "exit") == 0 || strcmp(input, "Exit") == 0) {
      printf("Goodbye.\n");
      exit(0);
    }

    input[strcspn(input, "\n")] = '\0';
    write(file, input, sizeof(input));

    read(file, input, sizeof(input));
    printf("New string: %s\n", input);
  }

  return 0;
}
