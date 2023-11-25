#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

const char* program_name;

void print_usage(FILE* stream, int exit_code) {
  fprintf(stream, "Usage: %s options [STRING]\n", program_name);
  fprintf(stream, " -h --help     Display this usage information.\n"
                  " -n --newline  Toggle newline output.\n");
  exit(exit_code);
}

int main(int argc, char *argv[]) {
  // assert(argc > 0);
  program_name = argv[0];
  if (argc < 2) {
    fprintf(stderr, "error: not enough arguments.\n");
    print_usage(stderr, 1);
  }

  /*
  const struct option long_options[] = {
    { "help", 0, NULL, 'h' },
    { "newline", 0,NULL, 'n' },
    { NULL, 0, NULL,0},
  }; */

  for (int i = 1; i <= (argc - 1); ++i)
    printf("%s ", argv[i]);
  printf("\n");

  return EXIT_SUCCESS;
}
