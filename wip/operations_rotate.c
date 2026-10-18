#include "push_swap.h"
#include "libft.h"

static void	rotate_top(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL)
		return;
	first = *stack;
	if (first == NULL || first->next == NULL)
		return;
	last = first;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_data *data)
{
	rotate_top(&data->stack_a);
	data->count_ra++;
	data->count_total++;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data)
{
	rotate_top(&data->stack_b);
	data->count_rb++;
	data->count_total++;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data)
{
	rotate_top(&data->stack_a);
	rotate_top(&data->stack_b);
	data->count_rr++;
	data->count_total++;
	ft_putstr_fd("rr\n", 1);
}