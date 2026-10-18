# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/12 11:18:39 by xin-jili          #+#    #+#              #
#    Updated: 2026/10/18 14:07:10 by xin-jili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAG = -rf

SRC_DIR = src
OBJ_DIR = obj
INCLUDES = includes

SRC := 01_parsing.c 02_parsing_utils.c create_index_stacks.c \
		create_stacks_utils.c sort_array_utils.c \
		operations_push.c operations_reverse_rotate.c \
		operations_rotate.c operations_swap.c

SRC := $(SRC:%.c=$(SRC_DIR)/%.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CCFLAGS) -I$(INCLUDES) -I$(LIBFT_PATH) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(RMFLAG) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clean fclean re
