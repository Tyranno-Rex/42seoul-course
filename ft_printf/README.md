# ft_printf

## Introduction

This project aims to recreate the functionality of the standard C library function `printf` from scratch. The function `ft_printf` provides formatted output to the standard output stream or another destination specified by the user.

## Files

- `ft_printf.c`: Main function for `ft_printf`.
- `ft_putchar.c`: Outputs a single character.
- `ft_putstring.c`: Outputs a string.
- `ft_putint.c`: Outputs an integer.
- `ft_puthex.c`: Outputs a hexadecimal number.
- `ft_pointer.c`: Outputs a pointer address.
- `ft_printf.h`: Header file for `ft_printf`.
- `ft_printf.pdf`: Project instructions.

## Main Functions

### `ft_printf`

```c
int ft_printf(const char *format, ...);
```

- **Description:** Outputs formatted data to the standard output stream according to the format string `format`. Additional arguments are passed as variadic arguments.

### `ft_percent`

```c
int ft_percent(const char format, va_list info);
```

- **Description:** Handles each conversion specifier (`%`) found in `format` string passed to `ft_printf`.

### Utility Functions

- `ft_putchar`: Outputs a single character.
- `ft_putstring`: Outputs a string.
- `ft_putint`: Outputs an integer.
- `ft_puthex`: Outputs a hexadecimal number.
- `ft_pointer`: Outputs a pointer address.

## Format Specifiers Supported

- `%c`: Character
- `%s`: String
- `%p`: Pointer
- `%d`, `%i`: Integer
- `%u`: Unsigned integer
- `%x`: Hexadecimal integer (lowercase)
- `%X`: Hexadecimal integer (uppercase)
- `%%`: Literal `%`

## Usage

To use `ft_printf`, include `ft_printf.h` and call `ft_printf` with the desired format string and any additional arguments:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    return (0);
}
```

## Compilation

Compile the project using the provided `Makefile`:

```bash
make
```

This will generate an executable or library depending on your `Makefile` configuration.

## Additional Notes

- Ensure to handle format specifiers and modifiers correctly as per the standard `printf` behavior.
- The project includes handling of basic conversions and flags, though additional features like precision and width can be added as extensions.

For detailed information, refer to `ft_printf.pdf`.

## Project Crawling
PROJECT_NAME : get_next_line
PROJECT_DESCRIPTION : This project aims to recreate the functionality of the standard C library function `printf` from scratch. The function `ft_printf` provides formatted output to the standard output stream or another destination specified by the user.
PROJECT_URL : 'https://github.com/Tyranno-Rex/42seoul-course/tree/main/get_next_line'
PROJECT_COMPLETION_STATUS : TRUE
PROJECT_MULTI : FALSE
PROJECT_SUBPROJECT : NONE
PROJECT_CATEGORY : 'implement'
PROJECT_NOTION : 'https://www.notion.so/1-2-ft_printf-7c2c294b2f7d4a408d0ae5d88eaf11ab?pvs=4'