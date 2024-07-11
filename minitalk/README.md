# Minitalk

## Introduction

Minitalk is a simple client-server communication program using signals in Unix. The project involves creating two programs: a server and a client, which communicate by sending and receiving signals.

## Files

- `Makefile`: Makefile for compiling the project.
- `includes`: Directory containing header files.
- `libft`: Directory containing a library of helper functions.
- `srcs`: Directory containing source files for mandatory part.
    | File | Description |
    - `server.c`: Implementation of the server program.
    - `client.c`: Implementation of the client program.
- `srcs_bonus`: Directory containing source files for bonus part.
- `Minitalk.pdf`: Documentation or detailed explanation of the project's requirements and behavior.
- `readme.md`: This file.

## Compilation

Compile the project using the provided `Makefile`. Run `make` in the root directory of the project:

```bash
make
```

This will generate executables for the server and client programs.

## Usage

### Server

The server waits for signals from the client and decodes them into characters.

```bash
./server
```

### Client

The client sends messages (strings) to the server using process ID (PID) and signals.

```bash
./client [server_pid] [message]
```

- `server_pid`: The process ID of the server (obtained from server's output).
- `message`: The message (string) to send to the server.

### Example

1. Start the server:

```bash
./server
```

2. In another terminal, send a message from the client:

```bash
./client [server_pid] "Hello"
```

Replace `[server_pid]` with the actual PID displayed by the server.

## Bonus

The bonus part of this project is implemented to handle edge cases or additional features beyond the basic requirements. However, the bonus implementation is identical to the mandatory part in this version.

## Additional Notes

- Ensure both server and client programs are running in separate terminals.
- Handle interruptions and edge cases gracefully, especially in signal handling and message transmission.
- Refer to `Minitalk.pdf` for detailed project requirements and behavior.

## Project Crawling
PROJECT_NAME : minitalk
PROJECT_DESCRIPTION : A simple client-server communication program using signals in Unix. The project involves creating two programs: a server and a client, which communicate by sending and receiving signals.
PROJECT_URL : 'https://github.com/Tyranno-Rex/42seoul-course/tree/main/minitalk'
PROJECT_COMPLETION_STATUS : TRUE
PROJECT_MULTI : FALSE
PROJECT_SUBPROJECT : NONE
PROJECT_CATEGORY : 'network', 'implement'
PROJECT_NOTION : 'https://www.notion.so/2-2-minitalk-ada12421e186403aacdcc77e99c909eb?pvs=4'