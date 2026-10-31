#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

int	get_stack_size(t_stack *stack)
{
	t_stack	*ptr;
	int	stack_size;

	ptr = stack;
	stack_size = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		stack_size++;
	}
	return (stack_size);
}

int	get_chunk_size(int n)
{
	int	chunk_size;

	if (n == 0)
		return (1);
	chunk_size = 0;
	while ((chunk_size + 1) * (chunk_size + 1) <= n)
		chunk_size++;
	return (chunk_size);
}

int	is_index_in_range(int index, int lo, int hi)
{
	return (index >= lo && index <= hi);
}



int	find_first(t_stack *stack, int lo, int hi)
{
	int	position;

	position = 0;
	while (stack != NULL)
	{
		if (is_index_in_range(stack->index, lo, hi))
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

int	find_last(t_stack *stack, int lo, int hi)
{
	int	position;
	int	last_found;

	position = 0;
	last_found = -1;
	while (stack != NULL)
	{
		if (is_index_in_range(stack->index, lo, hi))
			last_found = position;
		stack = stack->next;
		position++;
	}
	return (last_found);
}




int	main()
{
	int	array [] = {1, 23, 5, 33, 0};
	t_stack	*ptr;
	int lo = 2;
	int hi = 3;

	ptr = build_stack(array, 5);
	index_stack(ptr, array, 5);

	ft_printf("%d\n", get_stack_size(ptr));
	ft_printf("%d\n", get_stack_size(NULL));

	ft_printf("%d\n", get_chunk_size(500));

	ft_printf("%d\n", is_index_in_range(0, lo, hi));
	ft_printf("%d\n", find_first(ptr, lo, hi));

	ft_stack_clear(&ptr);
	return (0);
}