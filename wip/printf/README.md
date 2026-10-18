*This project has been created as part of the 42 curriculum by jkian.*

# Description
**ft_printf** is a library of functions that mimic the original printf function. The functions handle the following conversions:

- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

## Rules
**Language constraints** - the implementation avoids `printf`, `for` loops, external libraries, ternary operators (`? :`), `do...while` loops, `switch`/`case`/`default`, and `goto`.

**Memory** - no memory leaks are permitted. Any memory allocated on the heap must be freed before the end of execution.

**Makefile** - source files are listed explicitly (no wildcards), and the Makefile avoids unnecessary relinking. You must use the command ar to create your library. Using the libtool command is forbidden.

The buffer management of the original printf() does not have to be implemented.

# Instructions
**Requirements**
- A C compiler (`cc`, `gcc`, or `clang`)
- `make`
- `ar`

**Compiling**
```
make
```
This compiles all source files with `-Wall -Wextra -Werror` and archives them into `libftprintf.a` using `ar` (part of binutils)

**Cleaning up**
```
make clean     # removes the object (.o) files
make fclean    # removes object files and libftprintf.a
make re        # fclean, then rebuilds from scratch
```

**Using ft_printf in another project**

Include the header at the top of your `.c` file:
```
#include "ft_printf.h"
```

Place `libftprintf.a` and `ft_printf.h` in the same folder as `your_program.c`, then compile with:
```
cc your_program.c libftprintf.a -o your_program
```

# Resources
**Functions:**
- Kernighan, B. W., & Ritchie, D. M. (1988). The C programming language (2nd ed.). Prentice Hall. Section 7.3 ("Variable-length Argument Lists")
- [42's Norminette](https://github.com/42School/norminette)
- [man7.org](https://man7.org/linux/man-pages/man3/printf.3.html)

**Makefile:**
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)

**How AI was used:**
AI was explicitly instructed not to provide code. It was used to explain and illustrate concepts I couldn't fully grasp on my own, as a sounding board for my ideas, and to talk through different ways a given part of the subject could be implemented.

# Library description
- `README.md`
- `Makefile`
- `ft_printf.h`
- `.c` files:

The library can be simply understood in five parts:
**Main Printf Execution**
```c
int     ft_printf(const char *, ...);

```
**Write Utilities**
```c
void	ft_putchar(char c, int *ct);
void	ft_putstr(char *s, int *ct);
```

**Character & String Conversion**
```c
void	ft_char(int *i, int *ct, va_list *ap);
void	ft_str(int *i, int *ct, va_list *ap);
```

**Number Conversion**
```c
void	ft_dec_int(int *i, int *ct, va_list *ap);
void	ft_undec(int *i, int *ct, va_list *ap);
```

**Hex Conversion**
```c
void	ft_voidptr(int *i, int *ct, va_list *ap);
void	ft_hexlo(int *i, int *ct, va_list *ap);
void	ft_hexup(int *i, int *ct, va_list *ap);
```

