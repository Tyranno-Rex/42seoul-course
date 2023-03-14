#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif  

char *get_next_line(int fd)
{
    int     i = 0;
    int     rd;
    char    character;
    char    *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(sizeof(char)*1000000);
    if (!buffer)
        return (free(buffer), NULL);
    rd = read(fd, &character, 1);
    while (rd > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
        rd = read(fd, &character, 1);
    }
    buffer[i] = '\0';
    return (buffer);
}



int main()
{
    char *str;
    int fd;

    fd = open("text.txt", O_RDONLY); 
    str = get_next_line(fd);
    write(1, str, 5);
}