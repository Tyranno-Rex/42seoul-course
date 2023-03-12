#ifndef PRACTICE_2_H
#define PRACTICE_2_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char *get_next_line(int fd);

#endif