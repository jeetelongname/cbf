#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cbf.h"

int cellArr[3200];

char *clean(char *buffer) { return buffer; }

char *read_file(char *file_name) {
  int file_size;
  FILE *fp;
  unsigned long err = 0;

  fp = fopen(file_name, "r");

  if (!fp) {
    perror("Error while opening the file.\n");
    exit(errno);
  }

  fseek(fp, 0L, SEEK_END);
  file_size = ftell(fp); // get file size
  rewind(fp);

  char *buffer = malloc(file_size * sizeof(char));

  if (fp != NULL) {
    err = fread(buffer, file_size, sizeof(char), fp);
  }

  if (!err) {
    puts("somethings wrong I can feel it");
    exit(errno);
  }

  fclose(fp);
  return clean(buffer);
}

char *read_stdin() {
  ssize_t cap = 4096, /* Initial capacity for the char buffer */
      len = 0;        /* Current offset of the buffer */
  char *buffer = malloc(cap * sizeof(char));
  int c;

  /* Read char by char, breaking if we reach EOF or a newline */
  while ((c = fgetc(stdin)) && !feof(stdin)) {
    buffer[len] = c;

    /* When cap == len, we need to resize the buffer
     * so that we don't overwrite any bytes
     */
    if (++len == cap)
      /* Make the output buffer twice its current size */
      buffer = realloc(buffer, (cap *= 2) * sizeof(char));
  }

  /* Trim off any unused bytes from the buffer */
  buffer = realloc(buffer, (len + 1) * sizeof(char));

  /* Pad the last byte so we don't overread the buffer in the future */
  buffer[len] = '\0';

  return clean(buffer);
}

int eval(char *buffer) {
  printf("%s\n", buffer);

  free(buffer); // free the memory like a good boy
  return 0;
}

int main(int argc, char **argv) {
  int exit = 0;

  if (argc == 2) {
    if (strcmp(argv[1], "-") == 0)
      exit = eval(read_stdin());
    else
      exit = eval(read_file(argv[1]));
  } else if (argc < 2) {
    exit = 1;
    puts("To few arguments");
  } else {
    exit = 1;
    puts("To many arguments");
  }
  return exit;
}
