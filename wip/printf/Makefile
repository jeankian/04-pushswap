NAME = libftprintf.a
HEADERS = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = \
	ft_printf.c \
	ft_printf_string.c \
	ft_printf_num.c \
	ft_printf_hex.c \
	ft_printf_write.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
