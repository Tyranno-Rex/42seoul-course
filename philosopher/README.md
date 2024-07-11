# Philosophers

## Overview

The Philosophers project is a concurrency programming exercise based on the classic "Dining Philosophers Problem." This project is part of the 42Seoul curriculum and aims to provide a deeper understanding of threads, mutexes, and concurrent execution.

## Project Structure

```
Philosophers/
├── check_argv.c
├── init_mutex.c
├── init_thread.c
├── launch_thread.c
├── launch_waiter.c
├── main.c
├── Makefile
├── philo.h
├── Philosophers.pdf
├── README.md
├── utils.c
└── utils2.c
```

### File Descriptions

- **check_argv.c**: Handles the validation of command-line arguments.
- **init_mutex.c**: Initializes mutexes used for synchronization.
- **init_thread.c**: Initializes threads for philosophers.
- **launch_thread.c**: Launches philosopher threads.
- **launch_waiter.c**: Manages the waiter thread that monitors philosophers.
- **main.c**: The entry point of the application.
- **Makefile**: Instructions for building the project.
- **philo.h**: Header file containing function prototypes and global definitions.
- **Philosophers.pdf**: Project specification and detailed problem description.
- **utils.c**: Utility functions used throughout the project.
- **utils2.c**: Additional utility functions.

## Features

- Implements the Dining Philosophers Problem using threads and mutexes.
- Ensures proper synchronization to avoid deadlocks and race conditions.
- Handles command-line arguments for custom configurations.
- Provides utility functions to simplify thread and mutex management.


## Usage

Run the philosophers executable with the required arguments:
```sh
./philosophers <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

- `<number_of_philosophers>`: The number of philosopher threads.
- `<time_to_die>`: Time (in milliseconds) a philosopher can go without eating before dying.
- `<time_to_eat>`: Time (in milliseconds) a philosopher spends eating.
- `<time_to_sleep>`: Time (in milliseconds) a philosopher spends sleeping.
- `[number_of_times_each_philosopher_must_eat]` (optional): Number of times each philosopher must eat before the simulation ends.

### Example

```sh
./philosophers 5 800 200 200
```


## Project Details

- **project behavior rule** : eat-think-sleep
- **philosopher must use 2 forks to eat**
- **forks are placed between philosophers**
- **forks are protected by mutexes**
- **philosopher must not starve**
- **philosopher must not communicate with each other**
- **philosopher is represented by a thread**
- **philosopher cannot know the state of other philosophers**
- **eat → sleep → think**
- **if one philosopher dies, the simulation ends**

### main process

1. check_argv
2. init_mutex
3. init_thread
4. launch_thread
5. launch_waiter
6. join_thread
7. free_memory


### thread process

1. generate thread, wait for mutex
2. if even number, wait for a while
3. infinite loop
    1. check dieflag
    2. odd number philosopher → left-right, even number philosopher → right-left
    3. eat for a certain time (eating time and output order are important)
    4. put down forks
    5. check if all eaten
    6. wait for sleep time
    7. think output
    8. repeat

## Project Crawling
PROJECT_NAME : philosophers
PROJECT_DESCRIPTION : A simulation of the classic "Dining Philosophers" problem, demonstrating concepts of concurrency, threading, and synchronization. 
PROJECT_URL : 'https://github.com/Tyranno-Rex/42seoul-course/tree/main/philosopher'
PROJECT_COMPLETION_STATUS : TRUE
PROJECT_MULTI : FALSE
PROJECT_SUBPROJECT : NONE
PROJECT_CATEGORY : 'os', 'implement', 'optimization'
PROJECT_NOTION : 