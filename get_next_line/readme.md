# get_next_line

## Introduction

This project is aimed at creating a function named `get_next_line` which reads a line from a file descriptor. The function supports reading multiple file descriptors and handling multiple file descriptors simultaneously without losing the reading thread on each of them.

## Instructions

To compile the project, run:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c
```

Replace `xx` with your buffer size (e.g., 32, 64, 128).

## Functions

### `get_next_line`

```c
char *get_next_line(int fd);
```

- **Description:** Reads a line from the given file descriptor `fd`.

### `ft_read`

```c
char *ft_read(int fd, char *str);
```

- **Description:** Reads from the file descriptor `fd` into `str`.

### `ft_line`

```c
char *ft_line(char *str);
```

- **Description:** Extracts a line from `str` until a newline character.

### `ft_next_str`

```c
char *ft_next_str(char *str);
```

- **Description:** Moves `str` to the next position after the newline character.

### Utility Functions

- `ft_strlen`: Computes the length of a string.
- `ft_strchr`: Locates the first occurrence of a character in a string.
- `ft_strjoin`: Concatenates two strings.

## Usage

To use `get_next_line`, include `get_next_line.h` and call `get_next_line(fd)`, where `fd` is a valid file descriptor.

Example usage:

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("example_file.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    line = get_next_line(fd);
    while (line)
    {
        printf("%s\n", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
```

## Additional Notes

- Ensure to handle memory allocation and deallocation properly, especially with `malloc` and `free`.
- The project includes both mandatory and bonus parts for a unified implementation across functions.

For more detailed information, refer to `get_next_line.pdf`.

## Project Crawling
PROJECT_NAME : get_next_line
PROJECT_DESCRIPTION : A function that reads a line from a file descriptor. This project focuses file I/O and string manipulation. Bonus part includes handling multiple file descriptors.
PROJECT_URL : 'https://github.com/Tyranno-Rex/42seoul-course/tree/main/get_next_line'
PROJECT_COMPLETION_STATUS : TRUE
PROJECT_MULTI : FALSE
PROJECT_SUBPROJECT : NONE
PROJECT_CATEGORY : 'implement'
PROJECT_NOTION : 'https://www.notion.so/1-1-get_next_line-9b6a58dbc619478d8b8fd588aca73604?pvs=4'