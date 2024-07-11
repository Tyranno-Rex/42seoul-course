# Push Swap

## Overview

The `push_swap` project is a sorting algorithm challenge designed to deepen understanding of sorting algorithms, data structures, and algorithmic efficiency. The goal is to sort a stack of integers using a limited set of operations, with a focus on minimizing the number of operations. This README provides a detailed description of the project, including its structure and core algorithm.


## Core Algorithm: Radix Sort

The primary sorting algorithm used in this project is **Radix Sort**. The implementation leverages binary representation to sort the numbers in a non-comparative manner.

### Radix Sort Algorithm

```c
void radix_algo(t_stack **stack_a, t_stack **stack_b, int nbr_arg) {
    int bit;
    int i;
    int j;

    bit = binary_len(nbr_arg - 1);
    i = 0;
    while (i < bit) {
        j = 0;
        while (j < nbr_arg) {
            if (!((*stack_a)->value >> i & 1))
                move_push(stack_a, stack_b, 'b');
            else
                move_rotate(stack_a, 'a');
            j++;
        }
        while (*stack_b)
            move_push(stack_b, stack_a, 'a');
        i++;
    }
}
```

### Explanation

1. **Binary Length Calculation**: Calculate the number of bits needed to represent the largest number.
2. **Iterate Over Each Bit**: For each bit position:
   - Check each number's bit at the current position.
   - Push numbers with a 0 in that bit position to `stack_b`.
   - Rotate numbers with a 1 in that bit position in `stack_a`.
3. **Reassemble**: Move all numbers back from `stack_b` to `stack_a`.
4. Repeat for all bit positions until the stack is sorted.

## Features

- **Command-line Argument Validation**: Ensures valid input.
- **Stack Operations**: Implements push, pop, and rotate operations.
- **Sorting**: Efficiently sorts numbers using the radix sort algorithm.
- **Error Handling**: Manages invalid inputs and potential errors gracefully.

## Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/push_swap.git
   ```
2. Navigate to the project directory:
   ```sh
   cd push_swap
   ```
3. Build the project using the Makefile:
   ```sh
   make
   ```

## Usage

To run the `push_swap` program with a list of numbers:
```sh
./push_swap [numbers...]
```

### Example

```sh
./push_swap 4 2 3 1 5
```

To check if the solution is correct using the `checker` program:
```sh
./push_swap 4 2 3 1 5 | ./checker [numbers...]
```

### Example

```sh
./push_swap 4 2 3 1 5 | ./checker 4 2 3 1 5
```

## Testing

Use the provided `tester.sh` script to test various input scenarios and verify the correctness of the implementation.

```sh
cd checker
./tester.sh
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Project Crawling
PROJECT_NAME : push_swap
PROJECT_DESCRIPTION : A sorting algorithm visualization project. The goal is to sort a stack of numbers with the least number of operations using two stacks.
PROJECT_URL : 'https://github.com/Tyranno-Rex/42seoul-course/tree/main/push_swap'
PROJECT_COMPLETION_STATUS : TRUE
PROJECT_MULTI : FALSE
PROJECT_SUBPROJECT : NONE
PROJECT_CATEGORY : 'algorithm', 'implement', 'optimization'
PROJECT_NOTION : 'https://www.notion.so/2-3-push_swap-fcc5529e03644ad7924eab2fe6139d5c?pvs=4'