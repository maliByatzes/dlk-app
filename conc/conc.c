#include <assert.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

const char *program_name;

void print_usage(FILE *stream, int exit_code) {
  fprintf(stream, "Usage: %s [OPTION]... [FILE]...\n", program_name);
  fprintf(stream, "Concantenate FILE(s) to the standard output.\n");
  fprintf(stream, "\n");
  fprintf(stream, "With no FILE, or when FILE is -, read standard input.\n");
  fprintf(stream, "\n");
  fprintf(stream, "Options:\n");
  fprintf(stream, "\t-h, --help             Display this usage information.\n");
  fprintf(stream, "\n");
  fprintf(stream, "Examples:\n"
                  "\tconc f - g  Ouputs f's contents, then standard input, "
                  "then g's contents.\n"
                  "\tconc        Copy standard input to standard output.\n");
  exit(exit_code);
}

int main(int argc, char *argv[]) {
  assert(argc > 0);
  program_name = argv[0];

  const char *short_opt = "h";
  const struct option long_opt[] = {
      {"help", 0, NULL, 'h'},
      {NULL, 0, NULL, 0},
  };
  int next_option = 0;

  do {
    next_option = getopt_long(argc, argv, short_opt, long_opt, NULL);

    switch (next_option) {
    case 'h':
      print_usage(stdout, 0);
    case '?':
      print_usage(stderr, 1);
    case -1:
      break;
    default:
      abort();
    }
  } while (next_option != -1);

  // TODO: Implement the base features here

  return 0;
}
