#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"

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

void	parsing(int argc, char **argv, int index, t_stack **stack_a)
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
		return ;
	}
	*stack_a = build_stack(array, array_size);
	if (!(*stack_a))
	{
		free(array);
		return ;
	}
	index_stack(*stack_a, array, array_size);
	free(array);
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
	parsing(argc, argv, i, stack_a);
	return (1);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack		*stack_a;

	stack_a = NULL;
	if (process_args(argc, argv, &stack_a) == 1)
		ft_putstr_fd("Parsing successful\n", 1);
	else
		ft_putstr_fd("Parsing failed\n", 2);
	t_stack	*ptr = stack_a;
	while (ptr != NULL)
	{
		printf("%d, ", ptr->index);
		ptr = ptr->next;
	}
	return(0);
}
