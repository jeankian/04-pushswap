#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static int *parse_multi_arg(int argc, char **argv, int index, int *array_size)
{
	int *array;

	*array_size = argc - index;
	array = str_to_int_array(argv + index, *array_size);
	return (array);
}

static int *parse_single_arg(char *argv, int *array_size)
{
	char **numstr;
	int *array;
	int	i;

	numstr = ft_split(argv, ' ');
	if (!numstr)
		return (NULL);
	i = 0;
	while (numstr[i])
		i++;
	if (i == 0)
	{
		cleanup_tree(numstr);
		return (NULL);
	}
	*array_size = i;
	array = str_to_int_array(numstr, *array_size);
	cleanup_tree(numstr);
	return (array);
}

int	parsing(int argc, char **argv, int index, t_stack **stack_a)
{
	int *array;
	int array_size;

	array_size = 0;
	if (argv[index + 1] == NULL)
		array = parse_single_arg(argv[index], &array_size);
	else
		array = parse_multi_arg(argc, argv, index, &array_size);
	if (array == NULL || array_size == 0 || !is_not_dup(array, array_size))
	{
		free(array);
		return (0);
	}
	*stack_a = build_stack(array, array_size);
	if (!(*stack_a))
	{
		free(array);
		return (0);
	}
	index_stack(*stack_a, array, array_size);
	free(array);
	return (1);
}

int	process_args(int argc, char **argv, t_stack **stack_a)
{
	int i;

	if (argc < 2)
		return (1);
	i = 1;
	while (is_flag(argv[i]))
	{
		i++;
		if (argv[i] == NULL)
			return (1);
	}
	if (!parsing(argc, argv, i, stack_a))
		return (0);
	return (1);
}

void	print_stack(t_stack *stack)
{

	while (stack != NULL)
	{
		ft_putnbr_fd(stack->content, 1);
		ft_putchar_fd(' ', 1);
		stack = stack->next;
	}
	ft_putchar_fd('\n', 1);
}


int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data,sizeof(data));

	if (process_args(argc, argv, &data.stack_a) == 1)
		ft_printf("Parsing successful\n");
	else
		ft_printf("Parsing failed\n");
	
	t_stack	*ptr = data.stack_a;

	while (ptr != NULL)
	{
		ft_printf("%d, ", ptr->index);
		ptr = ptr->next;
	}
	
	ft_printf("\n");
	print_stack(data.stack_a);
	sa(&data);
	print_stack(data.stack_a);

	ft_stack_clear(&data.stack_a);
	return(0);
}