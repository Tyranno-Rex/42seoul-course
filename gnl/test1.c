#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

char *get_next_line(int fd)
{
    int rd;
    int i = 0;
    char character;
    char *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = (char *)malloc(sizeof(char)*10000000);
    if (!buffer)
        return (NULL);
    rd = read(fd, &character, 1);
    while (rd > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
        rd = read(fd, &character, 1);
    }
    buffer[i] = '\0';
    if (i == 0 && rd <= 0)
        return (NULL);
    return (buffer);
}

int main()
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY); 
    line = get_next_line(fd);
    write(1, line, 5);
    
}