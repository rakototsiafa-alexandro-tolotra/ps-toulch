*This project has been created as part of the 42 school program by arakotot.*

## Descriptions

**Libft** is a C library that implements a collection of standard C library functions and additional utility functions. The goal of this project is to understand how common functions work at a low level and to create a reusable library of functions that can be used in future projects.

### Objectives

- Implement standard C library functions (`libc`).
- Create additional utility functions for string manipulation and memory management.
- Develop linked list operations for dynamic data structures.
- Produce well-structured, efficient, and reusable code.


## Instructions

### Compilation

- Build the library:

```bash
make
```

This produces the static library `libft.a` and object files.

- Clean targets:

```bash
make clean    # remove object files
make fclean   # remove object files and libft.a
make re       # fclean then make
```

- Build a quick test or example without `libft.a`:

```bash
cc -Wall -Wextra -Werror test_ft_bzero.c ft_bzero.c -o test
```

- Build an example that links against `libft.a`:

```bash
cc -Wall -Wextra -Werror example.c -L. -lft -o example
```

### Installation

- Use locally in a project (recommended):

```bash
make
cp libft.a libft.h /path/to/your/project/
```

- (Optional) Install system-wide (requires sudo):

```bash
sudo cp libft.a /usr/local/lib/
sudo cp libft.h /usr/local/include/
sudo ldconfig
```

### Execution

- Run a compiled test binary:

```bash
./test            # runs test program built without libft.a
./example         # runs program linked with libft.a
```

- Example with arguments (if the test accepts them):

```bash
./test 5          # example: zero 5 bytes in ft_bzero test
```

### Usage

To use `libft` in your project:

1. Copy `libft.a` and `libft.h` to your project directory.
2. Include the header in your C files:

```c
#include "libft.h"
```

3. Compile your project and link with libft:

```bash
cc -Wall -Wextra -Werror your_program.c -L. -lft -o your_program
```

### Testing

To run the test suite:

1. Search "Libft tester" in google and clone the project test github Tripouille/libftTester.
2. include libftTester in your project and run this command :

```bash
cd libftTester
make
```

## Resources

### C Standard Library References

- [Linux man-pages - stdlib.h](https://man7.org/linux/man-pages/man0/stdlib.h.0p.html)
- [C Standard Library - cppreference](https://en.cppreference.com/w/c)

### Memory Management

- [Dynamic Memory Allocation in C](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c/)

### Linked Lists

- [Linked Lists - Introduction and Implementation](https://www.geeksforgeeks.org/linked-list-set-1-introduction/)

### AI Assistance

- Github Copilot Chat : Request for explanation of complex lines of code and how the file works, and also for error correction.

