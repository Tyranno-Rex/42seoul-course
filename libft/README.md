```markdown
# Libft

Libft is a custom implementation of standard C library functions. This library provides a range of functions for string manipulation, memory management, and linked list operations. The goal of this project is to deepen understanding of fundamental C programming concepts and to create a reusable library for future projects.

## Table of Contents
- [Functions](#functions)
- [Usage](#usage)
- [Installation](#installation)
- [Files](#files)
- [License](#license)

## Functions

### String Manipulation
- `ft_atoi.c` - Converts a string to an integer.
- `ft_isalnum.c` - Checks if a character is alphanumeric.
- `ft_isalpha.c` - Checks if a character is alphabetic.
- `ft_isascii.c` - Checks if a character is an ASCII character.
- `ft_isdigit.c` - Checks if a character is a digit.
- `ft_isprint.c` - Checks if a character is printable.
- `ft_itoa.c` - Converts an integer to a string.
- `ft_strchr.c` - Locates the first occurrence of a character in a string.
- `ft_strdup.c` - Duplicates a string.
- `ft_striteri.c` - Applies a function to each character of a string with its index.
- `ft_strjoin.c` - Joins two strings.
- `ft_strlcat.c` - Concatenates strings with size limitation.
- `ft_strlcpy.c` - Copies a string with size limitation.
- `ft_strlen.c` - Computes the length of a string.
- `ft_strmapi.c` - Applies a function to each character of a string to create a new string.
- `ft_strncmp.c` - Compares two strings up to a specified number of characters.
- `ft_strnstr.c` - Locates a substring within a string.
- `ft_strrchr.c` - Locates the last occurrence of a character in a string.
- `ft_strtrim.c` - Trims characters from the beginning and end of a string.
- `ft_substr.c` - Extracts a substring from a string.
- `ft_tolower.c` - Converts a character to lowercase.
- `ft_toupper.c` - Converts a character to uppercase.

### Memory Management
- `ft_bzero.c` - Sets all bytes in a buffer to zero.
- `ft_calloc.c` - Allocates memory and initializes it to zero.
- `ft_memccpy.c` - Copies memory until a character is found.
- `ft_memchr.c` - Scans memory for a character.
- `ft_memcmp.c` - Compares memory blocks.
- `ft_memcpy.c` - Copies memory area.
- `ft_memmove.c` - Moves memory area.
- `ft_memset.c` - Fills memory with a constant byte.

### File Descriptor Operations
- `ft_putchar_fd.c` - Outputs a character to a file descriptor.
- `ft_putendl_fd.c` - Outputs a string followed by a newline to a file descriptor.
- `ft_putnbr_fd.c` - Outputs an integer to a file descriptor.
- `ft_putstr_fd.c` - Outputs a string to a file descriptor.

### Linked List Operations
- `ft_lstadd_back.c` - Adds a new element to the end of a list.
- `ft_lstadd_front.c` - Adds a new element to the front of a list.
- `ft_lstclear.c` - Deletes and frees the entire list.
- `ft_lstdelone.c` - Deletes and frees a single list element.
- `ft_lstiter.c` - Iterates over a list and applies a function to each element.
- `ft_lstlast.c` - Returns the last element of a list.
- `ft_lstmap.c` - Creates a new list by applying a function to each element of an existing list.
- `ft_lstnew.c` - Creates a new list element.
- `ft_lstsize.c` - Counts the number of elements in a list.

## Usage
To use the libft library in your project, include the header file `libft.h` and link the compiled library.

```c
#include "libft.h"

int main() {
    char *str = ft_strdup("Hello, World!");
    printf("%s\n", str);
    free(str);
    return 0;
}
```

## Installation
1. Clone the repository:
    ```sh
    git clone https://github.com/Tyranno-Rex/42seoul-course.git
    ```
2. Navigate to the project directory:
    ```sh
    cd Libft
    cd libft
    ```
3. Compile the library:
    ```sh
    make
    ```

## Files
- `libft.h` - Header file containing function prototypes and necessary includes.
- `Makefile` - Script to compile the library.
- `Libft.pdf` - Detailed description and requirements of the libft project.
- Source files for each function listed above.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Summary
- [notion] : https://www.notion.so/0-libft-5eac5697c9f340a28a47601182c109cb

## Project Crawling
PROJECT_NAME : libft
PROJECT_DESCRIPTION : A custom implementation of standard C library functions, providing a range of functions for string manipulation, memory management, and linked list operations. The goal is to deepen understanding of fundamental C programming concepts and create a reusable library for future projects.
PROJECT_URL : 'https://github.com/Tyranno-Rex/42seoul-course/tree/main/libft'
PROJECT_COMPLETION_STATUS : TRUE
PROJECT_MULTI : FALSE
PROJECT_SUBPROJECT : NONE
PROJECT_CATEGORY : 'implement'
PROJECT_NOTION : 'https://www.notion.so/0-libft-5eac5697c9f340a28a47601182c109cb'
