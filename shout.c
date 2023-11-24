#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  assert(argc > 0);
  if (argc < 2) {
    printf("Not enough arguments. Please run: %s [message]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i <= (argc - 1); ++i)
    printf("%s ", argv[i]);
  printf("\n");

  return EXIT_SUCCESS;
}
