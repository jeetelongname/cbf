#ifndef CBF_H_
#define CBF_H_

typedef enum { true, false } Bool;

char *clean(char *buffer);
char *read_file(char *file_name);
char *read_stdin();
int eval(char *buffer);

#endif // CBF_H_
