#include "test6.h"
char *get_next_line(int fd)
{
    int i = 0;
    int rd;
    char character;
    char *buffer = malloc(1000000);

    if (fd < 0)
        return (free(buffer), NULL);
    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!rd && !buffer[i-1]) || rd < 0)
        return (free(buffer), NULL);
    buffer[i] = '\0';
    return (buffer);
}
#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd;
    char *line;
    fd = open("text.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("%s", line);
}