#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd)
{
    int i = 0;
    int rd;
    char *buffer;
    char character;

    if (BUFFER_SIZE <=0 || fd < 0)
        return (NULL);
    buffer = (char) malloc(sizeof(char) * 100000);
    if (!buffer)
        return (free(buffer), NULL);
    rd = read(fd, &character, 1);
    while (rd)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
        rd = read(fd, &character, 1);
    }
    buffer = '\0';
    return (buffer);
}