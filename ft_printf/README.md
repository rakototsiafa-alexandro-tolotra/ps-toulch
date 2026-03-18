*This project has been created as part of the 42 curriculum by arakotot*.

## Description

The ft_printf project is a fundamental exercise at 42 that involves recoding the standard C library printf() function. The primary goal is to learn how to handle variadic arguments in C using the va_list, va_start, va_arg, and va_end macros. This implementation, compiled as a library named libftprintf.a, provides a versatile tool for formatted output in future projects.

**The function supports the following conversions :**

   - ``%c:`` Prints a single character.

   - ``%s:`` Prints a string.

   - ``%p:`` Prints a void pointer in hexadecimal format.

   - ``%d / %i:`` Prints a decimal/integer (base 10).

   - ``%u:`` Prints an unsigned decimal number.

   - ``%x / %X:`` Prints a number in hexadecimal (base 16) in lowercase or uppercase.

   - ``%%:`` Prints a percent sign.


## Instructions

To retrieve the project on your machine, clone the git repositpory:
### Clonning this repository

```bash
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-0c355133-1b2f-4472-8760-4a31ae838708-7263468-arakotot ft_printf
```
```bash
cd ft_printf
```
This commands downloads the entire project to a folder ft_printf.

### Compilation

The project includes a ``Makefile`` that compiles the source files using ``cc`` with the flags ``-Wall -Wextra -Werror``.

To compile the library, run the following command in your terminal :
```bash
make
```
This will generate the `libftprintf.a` library at the root of the repository.

### Avalaible Rules :

- `make or make all` : Compiles the library.

- `make clean` : Removes object files (.o).

- `make fclean` : Removes object files and the libftprintf.a library.

- `make re` : Recompiles the entire project from scratch.

### Usage

To use `ft_printf` in your own C project, include the header file :
```c
#include "ft_printf.h"
```
To use this library, you also need to copy the libft folder into your project.

Use this `main.c` file to test this project and put this file in the main project folder :
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:05:39 by arakotot          #+#    #+#             */
/*   Updated: 2026/02/24 11:05:42 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int ret_ft;
    int ret_std;

    printf("--- TESTS DES CARACTERES ET CHAINES ---\n");
    // Test basique %c, %s, %%
    ret_ft = ft_printf("Mien: %c | %s | %%\n", 'A', "Hello 42");    
    ret_std = printf("Orig: %c | %s | %%\n", 'A', "Hello 42");
    printf("Retours: ft=%d | std=%d\n\n", ret_ft, ret_std);

    // Test NULL string (Exigence critique)
    ret_ft = ft_printf("Mien NULL: %s\n", (char *)NULL);
    ret_std = printf("Orig NULL: %s\n", (char *)NULL);
    printf("Retours: ft=%d | std=%d\n\n", ret_ft, ret_std);

    printf("--- TESTS DES ENTIERS (%%d, %%i, %%u) ---\n");
    // Test limites INT_MIN / INT_MAX
    ft_printf("Mien: %d | %i | %u\n", INT_MIN, INT_MAX, UINT_MAX);
    printf("Orig: %d | %i | %u\n\n", INT_MIN, INT_MAX, UINT_MAX);

    printf("--- TESTS HEXADECIMAUX ET POINTEURS ---\n");
    // Test %x, %X et %p
    int n = 42;
    void *ptr = &n;
    ft_printf("Mien: %x | %X | %p\n", 255, 255, ptr);
    printf("Orig: %x | %X | %p\n\n", 255, 255, ptr);

    // Test pointeur NULL
    ft_printf("Mien ptr NULL: %p\n", NULL);
    printf("Orig ptr NULL: %p\n", NULL);

    return (0);
}
```
I'm going to show you all the steps to test the project :
```bash
make
cc -Wextra -Wall -Werror main.c libftprintf.a -I. && valgrind --leak-check=full ./a.out
```

## Resources

### Documentation

- [Man7 page - printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html).
- [IBM - Documentation](https://www.ibm.com/docs/fr/i/7.5.0?topic=functions-printf-print-formatted-characters).

### Tutorials

- [koor - Tuto C](https://koor.fr/C/cstdio/fprintf.wp)
- [Gemini AI](https://gemini.google.com)

### IA Assistance

Gemini AI : Request for explanation of complex lines of code and how the file works, and also for error correction.


## Algorithm and Data Structures

The core of this implementation relies on a dispatching algorithm.

- **Parsing:** The function iterates through the format string. Characters are written directly to the standard output until a `%` sign is encountered.
- **Conversion Handling:** Once a `%` is detected, the next character is identified as a conversion specifier. A series of conditional checks (or a jump table/function pointers) directs the variadic argument to the appropriate sub-function.
- **Variadic Processing:** The va_arg macro is used to retrieve arguments of the correct type (e.g., int for `%c`, `char *` for `%s`).
- **Base Conversion:** For hexadecimal and unsigned types, a recursive algorithm or a buffer-based approach is used to convert integers into the required string representation.

This structure ensures modularity, making it easy to debug specific conversions without affecting the entire function.