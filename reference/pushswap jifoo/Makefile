NAME        = push_swap
CHECKER     = checker

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS_DIR = ./src/
INCS_DIR = ./include

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3

BONUS_FLAGS = -DBONUS=1 -g3

SRCS_FILES  = operations_reverse_rotate.c operations_rotate.c operations_swap.c \
			  operations_push.c presort_and_index.c \
			  utils_operation.c utils_parsing.c utils_parsing_2.c \
			  build_stack.c utils_initialization.c utils_sorting.c \
			  utils_medium_algorithm.c utils_sorting_2.c \
			  medium_algorithm.c simple_algorithm.c small_number_algorithm.c \
			  utils_small_number_algorithm.c complex_algorithm.c \
			  utils_complex_algorithm.c disorder_computation.c utils_checker.c \
			  adaptive_algorithm.c benchmark_mode.c utils_benchmark_mode.c

SRCS        = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS        = $(SRCS:.c=.o)
MAIN_OBJ    = $(SRCS_DIR)main.o

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(CHECKER)

re: fclean all

bonus: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(BONUS_FLAGS)" compile_bonus

compile_bonus: all $(CHECKER)

$(CHECKER): $(SRCS_DIR)checker.c $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_FLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) \
		$(SRCS_DIR)checker.c $(OBJS) $(LIBFT) -o $(CHECKER)

.PHONY: all clean fclean re bonus
