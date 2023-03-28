#ifndef TEST5_H
#define TEST5_H

char *get_next_line(int fd);

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>

#endif