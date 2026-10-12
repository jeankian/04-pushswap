*This project has been created as part of the 42 curriculum by \<xin-jili\>*

# Description
### Brief overview: 
This project involves creating a C library consisting of various functions that will be helpful for future 42 school C projects. The functions in the library are a combination of self-implemented external functions from the libc, as well as additional functions that either does not exist in the libc, or exist in an alternate form.

### Goal:
The aim of this project is to deepen my understanding of how certain useful functions work by recreating them myself and learning how to use them effectively.

# Instructions
### execution:
from the command-line interface, prompt:  
`make` or `make all` or `make libft.a`    
to compile the **libft.a** library

uncomment the main from the functions you want to test, then prompt: <br />
`cc <ft_test.c> libft.a` and `./a.out` <br />
to **run the program**

`make clean`
to clean all the object files (*.o)

`make fclean`
to clean all object files (*.o) and remove the **libft.a** library

`make re`
to recompile the **libft.a** library


# Resources
reimplementation of functions from the libc was based on the `man` page that can be accessed from the terminal

other external resources used includes:
- [GeeksForGeeks](https://www.geeksforgeeks.org/)
- [Stack Overflow](https://stackoverflow.com/)
- [Medium](https://medium.com/)
- [GitHub Docs](https://docs.github.com/)

AI usage: AI was only used to reaffirm my understanding of programming concepts. AI was not used to generate any code.


# Library Description
The library created for this project involves functions that can be categorized as follow:

## Part 1: Libc functions
### Character Classification Functions
*returns 1 if character matches what is being checked, otherwise return 0*<br />
- **ft_isalpha** - checks for an alphabetic character
- **ft_isdigit** - checks for a digit
- **ft_isalnum** - checks for an alphabetic character or a digit
- **ft_isascii** - checks for ASCII character set
- **ft_isprint** - checks for printable character

### Character Case Conversion Functions
- **ft_tolower** - converts uppercase to lowercase character
- **ft_toupper** - converts lowercase to uppercase character

### Memory Functions
- **ft_memset** - fill n bytes of memory with a constant byte
- **ft_bzero** - fill n bytes of memory with zeroes
- **ft_memcpy** - copies n bytes from a memory source to a memory destination without handling overlapping areas
- **ft_memmove** - copies n bytes from a memory source to a memory destination and handles memory overlaps
- **ft_memchr** - scans n bytes of memory for the first instance of a character
- **ft_memcmp** - compares n bytes of memory areas `s1` and `s2`, then returns the difference in ascii value
- **ft_calloc** - allocates memory based on nmemb elements of size bytes, then allocated memory is set to zero

### String Functions
- **ft_strlcpy** - copies up to `size - 1` characters from the string source to destination, guarantees NULL-terminated results
- **ft_strlcat** - appends at most `size - length of destination - 1 bytes` from source string to the end of destination, result is NULL-terminated
- **ft_strchr** - returns a pointer to the first occurance of the given character in the string
- **ft_strrchr** - returns a pointer to the last occurance of the given character in the string
- **ft_strncmp** - compares n bytes of `s1` and `s2` using unsigned characters, then returns the difference in ascii value
- **ft_strnstr** - searches len amount of characters in a string for a substring. If found, returns the pointer to the first character of the first occurence of little 
- **ft_atoi** - converts a string to an integer 
- **ft_strdup** - returns a duplicated string

## Part 2: Additional Functions 
### String Functions
- **ft_substr** - returns a substring from given string `s` starting at index `start` and has a maximum length of `len`
- **ft_strjoin** - returns a new string, which is the result of joining `s1` and `s2` 
- **ft_strtrim** - returns a copy of `s1` with characters from `set` removed from the beginning and the end
- **ft_split** - splits string `s` by character `c`, stores and returns the results in an array of strings
- **ft_itoa** - converts integer to string
- **ft_strmapi** - returns a new string, which was the result of succesive applications of the function `f` to each character of string `s`
- **ft_striteri** - applies the function `f` to each character of string `s`

### File Descriptor Functions
- **ft_putchar_fd** - outputs character to specificied file descriptor
- **ft_putstr_fd** - outputs string to the specified file descriptor
- **ft_putendl_fd** - outputs string followed by a newline to the specified file descriptor
- **ft_putnbr_fd** - outputs integer to the specified file descriptor

## Part 3: Linked List
- **ft_lstnew** - returns a new node with `content` member being initalized with the given parameter `content`, the `next` member is initialized to NULL
- **ft_lstadd_front** - add a node to the beginning of the list
- **ft_lstadd_back** - add a node to the end of the list
- **ft_lstsize** - returns the number of nodes in the list
- **ft_lstlast** - returns the last node of the list
- **ft_lstdelone** - frees a node's content using the `del` function, then frees the node itself
- **ft_lstclear** - deletes and frees the given node and all its successors
- **ft_lstiter** - applies the function `f` to the content of each node in the list
- **ft_lstmap** - creates a new list that contains the succesive applications of the function `f` to the content of each node in the original list

