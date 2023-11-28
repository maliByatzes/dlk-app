#include <assert.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

const char *program_name;

void print_usage(FILE *stream, int exit_code) {
  fprintf(stream, "Usage: %s options [STRING]\n", program_name);
  fprintf(stream, " -h --help     Display this usage information.\n"
                  " -n --newline  Toggle newline output.\n");
  exit(exit_code);
}

int main(int argc, char *argv[]) {
  assert(argc > 0);
  program_name = argv[0];
  if (argc < 2) {
    fprintf(stderr, "error: not enough arguments.\n");
    print_usage(stderr, 1);
  }

  const char *short_options = "hne";
  const struct option long_options[] = {
      {"help", 0, NULL, 'h'},
      {"newline", 0, NULL, 'n'},
      {NULL, 0, NULL, 0},
  };
  int next_option;
  int newline_toggle = 0;

  do {
    next_option = getopt_long(argc, argv, short_options, long_options, NULL);

    switch (next_option) {
    case 'h':
      print_usage(stdout, 0);
    case 'n':
      newline_toggle = 1;
      break;
    case '?':
      print_usage(stderr, 1);
    case -1:
      break;
    default:
      abort();
    }
  } while (next_option != -1);

  if (newline_toggle) {
    for (int i = 2; i <= (argc - 1); ++i) {
        if (i == (argc-1)) {
            printf("%s", argv[i]);
        } else {
            printf("%s ", argv[i]);
        }
    }
  } else {
    for (int i = 1; i <= (argc - 1); ++i) {
        if (i == (argc-1)) {
            printf("%s", argv[i]);
        } else {
            printf("%s ", argv[i]);
        }
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
