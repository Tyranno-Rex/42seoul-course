# Minishell

## Overview

Minishell is a simple shell program that mimics the behavior of common Unix shells. It is developed as part of the 42Seoul curriculum to enhance understanding of system calls, process management, and basic shell functionalities. Minishell supports executing commands, handling environment variables, and basic input/output redirections.

## Features

- Execute common shell commands with arguments.
- Handle environment variables (`ENV`).
- Implement basic shell built-ins like `cd`, `echo`, `pwd`, `export`, `unset`, and `exit`.
- Support for command pipelines (`|`).
- Handle input (`<`) and output (`>`, `>>`) redirections.
- Basic error handling and signal management.

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/minishell.git
   ```
2. Navigate to the project directory:
   ```sh
   cd minishell
   ```
3. Build the project using the Makefile:
   ```sh
   make
   ```

## Usage

Run the minishell executable:
```sh
./minishell
```

### Shell Built-ins

Minishell includes the following built-in commands:

- `cd [directory]`: Change the current directory to the specified path.
- `echo [string]`: Display a line of text.
- `pwd`: Print the current working directory.
- `export [name[=value] ...]`: Set environment variables.
- `unset [name ...]`: Unset environment variables.
- `exit [n]`: Exit the shell with an optional exit status.

### Example Commands

```sh
minishell> echo Hello, world!
Hello, world!

minishell> pwd
/home/user/minishell

minishell> cd ..
minishell> pwd
/home/user

minishell> export MY_VAR=42
minishell> echo $MY_VAR
42

minishell> unset MY_VAR
minishell> echo $MY_VAR

minishell> ls -l | grep minishell
```

---

## Project Crawling
PROJECT_NAME : minishell
PROJECT_DESCRIPTION : A simple shell implementation in C. This project covers command parsing, process management, and signal handling. 
PROJECT_URL : 'https://github.com/Tyranno-Rex/42seoul-course/tree/main/minishell'
PROJECT_COMPLETION_STATUS : TRUE
PROJECT_MULTI : FALSE
PROJECT_SUBPROJECT : NONE
PROJECT_CATEGORY : 'implement', 'os', 'teamTask'
PROJECT_NOTION : 'https://www.notion.so/3-2-minishell-42a9eea29b3a4b1db3077e2ae01c18de?pvs=4'