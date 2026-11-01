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



int	find_first_pos(t_stack *stack, int lo, int hi)
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

int	find_last_pos(t_stack *stack, int lo, int hi)
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

void	bring_to_top_a(t_data *data, int lo, int hi)
{
	int	first_pos;
	int	last_pos;
	int	top_cost;
	int	bot_cost;

	first_pos = find_first_pos(data->stack_a, lo, hi);
	if (first_pos == -1)
		return;
	last_pos = find_last_pos(data->stack_a, lo, hi);
	top_cost = first_pos;
	bot_cost = get_stack_size(data->stack_a) - last_pos;
	if (top_cost <= bot_cost)
	{
		while (top_cost > 0)
		{
			ra(data);
			top_cost--;
		}
	}
	else
	{	
		while (bot_cost > 0)
		{
			rra(data);
			bot_cost--;
		}
	}
}

void	push_chunks_to_b(t_data *data)
{
	int	lo;
	int	hi;
	int	stack_a_size;
	int	chunk_size;
	int	pushed;

	stack_a_size = get_stack_size(data->stack_a);
	chunk_size = get_chunk_size(stack_a_size);
	lo = 0;
	hi = chunk_size - 1;
	pushed = 0;
	while(data->stack_a != NULL)
	{
		bring_to_top_a(data, lo, hi);
		pb(data);
		pushed++;
		if (pushed == hi + 1)
		{
			lo = lo + chunk_size;
			hi = hi + chunk_size;
		}
	}
}


int	main()
{
	int	array [] = {1, 23, 0, 5, 3};
	t_data	data;
	t_stack *ptr;

	ft_bzero(&data,sizeof(data));

	data.stack_a = build_stack(array, 5);
	index_stack(data.stack_a, array, 5);

	ptr = data.stack_a;
	ft_printf("stack a:");
	while(ptr != NULL)
	{
		ft_printf("%d, ", ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");

	push_chunks_to_b(&data);

	ptr = data.stack_a;
	ft_printf("stack a:");
	while(ptr != NULL)
	{
		ft_printf("%d, ", ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");

	ptr = data.stack_b;
	ft_printf("stack b:");
	while(ptr != NULL)
	{
		ft_printf("%d, ", ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");

	// ft_printf("%d\n", get_stack_size(ptr));
	// ft_printf("%d\n", get_stack_size(NULL));

	// ft_printf("%d\n", get_chunk_size(500));

	// ft_printf("%d\n", is_index_in_range(0, lo, hi));
	// ft_printf("first seen at position: %d\n", find_first_pos(ptr, lo, hi));
	// ft_printf("last seen at position: %d\n", find_last_pos(ptr, lo, hi));

	ft_stack_clear(&data.stack_a);
	ft_stack_clear(&data.stack_b);
	return (0);
}