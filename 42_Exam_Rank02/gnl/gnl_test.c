#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1

char *get_next_line(int fd)
{
    int     i = 0;
    int     rd;
    char    character;
    char    *buffer = malloc(10000000);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free(buffer), NULL);
    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == "\n")
            break;
    }
    if ((!buffer[i] && !rd) || (rd < 0))
        return (free(buffer), NULL);
    buffer[i] = '\0';
    return (buffer);
}