# so_long

## Overview

The `so_long` project is a simple 2D game developed as part of the 42Seoul curriculum. The objective of this project is to enhance understanding of game development concepts, file I/O, graphics rendering, and event handling using the MiniLibX graphics library.

## Project Structure

```
so_long/
├── ft_printf/
├── get_next_line/
├── image/
├── libft/
├── maps/
├── so_long_bonus/
├── en.subject.pdf
├── image_render.c
├── image_setting.c
├── main.c
├── makefile
├── map_checker.c
├── map_is_clear.c
├── map_reader.c
├── map_utils.c
├── player_controller.c
├── README.md
├── so_long.h
├── so_long_utils.c
└── struct_init.c
```

### File Descriptions

- **ft_printf/**: Custom printf function implementation.
- **get_next_line/**: Function to read lines from a file descriptor.
- **image/**: Directory containing game images (sprites).
- **libft/**: Custom library with standard C functions.
- **maps/**: Directory containing map files for the game.
- **so_long_bonus/**: Additional features and enhancements for the game.
- **en.subject.pdf**: Project specifications and requirements.
- **image_render.c**: Handles rendering of images on the screen.
- **image_setting.c**: Manages the setup of game images.
- **main.c**: The entry point of the application.
- **makefile**: Instructions for building the project.
- **map_checker.c**: Validates the map structure and content.
- **map_is_clear.c**: Checks if the map can be cleared (player reaches the exit).
- **map_reader.c**: Reads the map file and loads it into the game.
- **map_utils.c**: Utility functions for map handling.
- **player_controller.c**: Manages player movements and interactions.
- **so_long.h**: Header file containing function prototypes and global definitions.
- **so_long_utils.c**: Utility functions used throughout the project.
- **struct_init.c**: Initializes the game structures.

## Features

- **Map Validation**: Ensures the map is correctly formatted and valid.
- **Player Movement**: Handles player movement within the game map.
- **Image Rendering**: Uses MiniLibX to render game images (sprites).
- **Event Handling**: Manages keyboard events for player control.
- **Game Mechanics**: Implements basic game mechanics such as collecting items and reaching the exit.

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/so_long.git
   ```
2. Navigate to the project directory:
   ```sh
   cd so_long
   ```
3. Build the project using the Makefile:
   ```sh
   make
   ```

## Usage

Run the `so_long` executable with a map file:
```sh
./so_long maps/map.ber
```

### Example

```sh
./so_long maps/level1.ber
```

### Map Format

The map file should be a `.ber` file containing the game map in a specific format:
- `1`: Wall
- `0`: Empty space
- `P`: Player start position
- `E`: Exit
- `C`: Collectible item

### Example Map (`map.ber`)

```
111111
1P0C01
100001
1C0E01
111111
```

## Controls

- `W`: Move up
- `A`: Move left
- `S`: Move down
- `D`: Move right
- `ESC`: Exit the game

---

## Project Crawling
PROJECT_NAME : so_long
PROJECT_DESCRIPTION : A simple 2D game developed as part of the 42Seoul curriculum to enhance understanding of game development concepts, file I/O, graphics rendering, and event handling using the MiniLibX graphics library.
PROJECT_URL : 'https://github.com/Tyranno-Rex/42seoul-course/tree/main/so_long'
PROJECT_COMPLETION_STATUS : TRUE
PROJECT_MULTI : FALSE
PROJECT_SUBPROJECT : NONE
PROJECT_CATEGORY : 'game&simulation', 'implement'
PROJECT_NOTION : 'https://www.notion.so/2-1-so_long-1903e08e54b34280a7babe1d7d068501?pvs=4'