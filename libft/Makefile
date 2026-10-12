# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/27 18:35:27 by xin-jili          #+#    #+#              #
#    Updated: 2026/10/12 11:14:37 by xin-jili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAG = -f
AR = ar -rcs
CFILES	:=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_print_char.c \
			ft_printf.c \
			ft_print_nbr.c \
			ft_print_str.c \
			ft_print_specifier.c \
			get_next_line.c \
			get_next_line_utils.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OFILES = $(CFILES:%.c=%.o)

%.o: %.c
	$(CC) $(CCFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)

clean:
	$(RM) $(RMFLAG) $(OFILES)

fclean:
	make clean
	$(RM) $(RMFLAG) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re