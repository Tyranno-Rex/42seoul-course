
# exam_rank04 : Microshell

## Introduction

Microshell is a simple command-line interpreter implemented in C, capable of executing basic commands and handling pipe operations.

## Functionality

The microshell program provides the following functionality:

- **Command Execution**: Executes commands entered via command-line arguments.
- **Built-in Command**: Supports the `cd` command to change the current working directory.
- **Piping**: Allows for basic pipe (`|`) operations between commands.
- **Error Handling**: Provides basic error messages for command execution failures.

## Files

- `microshell.c`: Contains the main implementation of the microshell program.
- `microshell.h`: Header file for microshell, defining functions and including necessary libraries.
- `README.md`: This file, providing an overview of the project and its functionality.

## Usage

To use microshell, compile the `microshell.c` file using a C compiler (e.g., `gcc`). Execute the compiled binary with appropriate command-line arguments to run commands and see their output.

### Example Usage

1. Compile the program:
   ```bash
   gcc -o microshell microshell.c
   ```

2. Run the microshell with commands:
   ```bash
   ./microshell ls -l | grep README.md ; cd ..
   ```

   This example demonstrates listing files in long format, piping the output to search for `README.md`, and changing the directory one level up.

## Notes

- Ensure proper command-line arguments when using the microshell to avoid errors related to command execution and piping operations.
- The program uses basic error handling to report issues with command execution and changes to the directory.

---

## Project Crawling
PROJECT_NAME : exam_rank04
PROJECT_DESCRIPTION : An exam testing the ability to implement more complex programs and handle advanced programming scenarios. microshell is a simple command-line interpreter capable of executing basic commands and handling pipe operations.
PROJECT_URL : 'https://github.com/Tyranno-Rex/42seoul-course/tree/main/exam_rank04'
PROJECT_COMPLETION_STATUS : TRUE
PROJECT_MULTI : FALSE
PROJECT_SUBPROJECT : NONE
PROJECT_CATEGORY : implement
PROJECT_NOTION : 'NONE'
