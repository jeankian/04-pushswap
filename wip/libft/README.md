*This project has been created as part of the 42 curriculum by jkian.*

# Description
**Libft** is a "build your own toolkit" project. It requires reimplementing a selection of standard C library functions, adding several useful custom functions, and building a small set of linked-list utilities - all compiled into a single static library. The goal is to produce a personal toolbox of reliable, from-scratch functions that can be reused across future projects in 42's Core Program.

The library is made up of 43 functions across three parts:

- **Part 1 - Libc functions:** reimplementations that match the prototypes and behavior of their original libc counterparts exactly, as defined in the man pages. The only difference is the `ft_` prefix added to each name.
- **Part 2 - Additional functions:** utility functions that either don't exist in the libc or exist there in a different form.
- **Part 3 - Linked list:** a small set of functions for creating, traversing, and manipulating a singly linked list.

## Rules
**Language constraints** - the implementation avoids `printf`, `for` loops, external libraries, ternary operators (`? :`), `do...while` loops, `switch`/`case`/`default`, and `goto`.

**Memory** - no memory leaks are permitted. Any memory allocated on the heap must be freed before the end of execution.

**Makefile** - source files are listed explicitly (no wildcards), and the Makefile avoids unnecessary relinking.

# Instructions
**Requirements**
- A C compiler (`cc`, `gcc`, or `clang`)
- `make`
- `ar`, part of binutils

**Compiling**
```
make
```
This compiles all source files with `-Wall -Wextra -Werror` and archives them into `libft.a` using `ar` (part of binutils).

**Cleaning up**
```
make clean     # removes the object (.o) files
make fclean    # removes object files and libft.a
make re        # fclean, then rebuilds from scratch
```

**Using libft in another project**

Include the header at the top of your `.c` file:
```
#include "libft.h"
```

Place `libft.a` and `libft.h` in the same folder as `your_program.c`, then compile with:
```
cc your_program.c libft.a -o your_program
```

# Resources
**Functions:**
- `man 3 <function>`
- [42's Norminette](https://github.com/42School/norminette)
- [man7.org](https://man7.org/)
- [freebsd.org](https://www.freebsd.org/)

**Makefile:**
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [GitHub Docs](https://docs.github.com/en)

**Header files:**
- [W3Schools - Organizing Code in C](https://www.w3schools.com/c/c_organize_code.php)

**How AI was used:**
AI was explicitly instructed not to provide code. It was used to explain and illustrate concepts I couldn't fully grasp on my own, as a sounding board for my ideas, and to talk through different ways a given part of the subject could be implemented.

# Library description
- `README.md`
- `Makefile`
- `libft.h`
- `.c` files:

**Part 1 - Libc functions**
```
int             ft_isalpha(int c);
int             ft_isdigit(int c);
int             ft_isalnum(int c);
int             ft_isascii(int c);
int             ft_isprint(int c);
size_t          ft_strlen(const char *s);
void            *ft_memset(void *s, int c, size_t n);
void            ft_bzero(void *s, size_t n);
void            *ft_memcpy(void *s1, const void *s2, size_t n);
void            *ft_memmove(void *s1, const void *s2, size_t n);
size_t          ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t          ft_strlcat(char *dst, const char *src, size_t dsize);
int             ft_toupper(int c);
int             ft_tolower(int c);
char            *ft_strchr(const char *s, int c);
char            *ft_strrchr(const char *s, int c);
int             ft_strncmp(const char *s1, const char *s2, size_t n);
void            *ft_memchr(const void *s, int c, size_t n);
int             ft_memcmp(const void *s1, const void *s2, size_t n);
char            *ft_strnstr(const char *big, const char *little, size_t len);
int             ft_atoi(const char *str);
void            *ft_calloc(size_t elnum, size_t elsize);
char            *ft_strdup(const char *s);
```

**Part 2 - Additional functions**
```
char            *ft_substr(const char *s, unsigned int start, size_t len);
char            *ft_strjoin(const char *s1, const char *s2);
char            *ft_strtrim(const char *s1, const char *set);
char            **ft_split(const char *s, char c);
char            *ft_itoa(int n);
char            *ft_strmapi(const char *s, char (*f)(unsigned int, char));
void            ft_striteri(char *s, void (*f)(unsigned int, char *));
void            ft_putchar_fd(char c, int fd);
void            ft_putstr_fd(char *s, int fd);
void            ft_putendl_fd(char *s, int fd);
void            ft_putnbr_fd(int n, int fd);
```

**Part 3 - Linked list**
```
t_list          *ft_lstnew(void *content);
void            ft_lstadd_front(t_list **lst, t_list *new);
unsigned int    ft_lstsize(t_list *lst);
t_list          *ft_lstlast(t_list *lst);
void            ft_lstadd_back(t_list **lst, t_list *new);
void            ft_lstdelone(t_list *lst, void (*del)(void *));
void            ft_lstclear(t_list **lst, void (*del)(void *));
void            ft_lstiter(t_list *lst, void (*f)(void *));
t_list          *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```
