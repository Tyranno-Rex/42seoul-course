#include "get_next_line.h"
#include <fcntl.h>


/*gnl 함수 설명*/
char *get_next_line(int fd)
{
    int     i = 0;
    int     rd;
    char    character;
    char    *buffer = malloc(10000);
    if (fd < 0 || BUFFER_SIZE <= 0)
	    return (free(buffer), NULL);
    while ((rd = read(fd, &character, 1)) > 0)
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
    buffer[i] =  '\0';
    return(buffer);
}

#include <stdio.h>

int main()
{
    char *line;
    int fd;

    fd = open("text.txt", O_RDONLY); 
    while ((line = get_next_line(fd)) != NULL)
        printf("%s", line);
    return (0);
}