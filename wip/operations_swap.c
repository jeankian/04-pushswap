#include "push_swap.h"
#include "libft.h"

static void	swap_top(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack == NULL)
		return;
	first = *stack;
	if (first == NULL || first->next == NULL)
		return;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_data *data)
{
	swap_top(&data->stack_a);
	data->count_sa++;
	data->count_total++;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *data)
{
	swap_top(&data->stack_b);
	data->count_sb++;
	data->count_total++;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *data)
{
	swap_top(&data->stack_a);
	swap_top(&data->stack_b);
	data->count_ss++;
	data->count_total++;
	ft_putstr_fd("ss\n", 1);
}