#include "practice_1.h"
#include <fcntl.h>

char *get_next_line(int fd)
{
    int     i = 0;
    int     rd = 0;
    char    character;
    char    *buffer = (char *)malloc(10000);

    if (BUFFER_SIZE <= 0)
        return (free(buffer), NULL);
    while (rd = read(fd, &character, 1))
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] = '\0';
    return (buffer);
}


int main()
{
    char    *str;
    int     fd;

    fd = open("text.txt", O_RDONLY);
    str = get_next_line(fd);
    write(1, str, 5);
}