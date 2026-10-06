*This project has been created as part of the 42 curriculum by jifoo.*

# Libft

## Description

Libft is a custom C library reimplementing standard `libc` functions, plus additional string, memory, and linked list
utilities. It's split into three parts: libc functions, additional functions, and a linked list module.

## Instructions

Build the library:

make

Other rules: `make clean` (remove `.o` files), `make fclean` (remove `.o`
files and `libft.a`), `make re` (rebuild from scratch).

To use in another project, copy the `libft` folder and include the header:

#include "libft/libft.h"

Then compile and link:

make -C libft
cc your_files.c -Lpath/to/libft -lft -o your_program

## Resources

- `man` pages for each reimplemented function
- 42 Norminette documentation for style compliance

**AI usage:** An AI assistant was used to explain concepts, and point out bugs (e.g., pointer dereferencing, operator precedence, memory leaks). It was not used to write
or generate function implementations directly.
