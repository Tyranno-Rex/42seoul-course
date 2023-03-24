#ifndef TEST_H
#define TEST_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

#endif