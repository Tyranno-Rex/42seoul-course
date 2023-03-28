#ifndef TEST6_H
#define TEST6_H


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>
char *get_next_line(int fd);

#endif