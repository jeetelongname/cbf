#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int cellArr[3200];

int read_file(int argc, char *argv[]) {
  char ch, file_name[30];
  int file_size;
  FILE *fp;

  fp = fopen(argv[1], "r");

  if (fp == 0x0) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  fseek(fp, 0L, SEEK_END);
  file_size = ftell(fp);
  rewind(fp);

  printf("%d\n", file_size);
  fclose(fp);
  return 0;
}

int main(int argc, char *argv[]) {
  int exit;

  if (argc == 2) {
    exit = read_file(argc, argv);
  } else if (argc < 2) {
    exit = 1;
    puts("To few arguments");
  } else {
    exit = 1;
    puts("To many arguments");
  }
  return exit;
}
