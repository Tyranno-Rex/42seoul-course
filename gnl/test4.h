#ifndef TES4_H
#define TEST4_H

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#endif