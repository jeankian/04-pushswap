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
void	sa(t_stack **a)
{
	swap_top(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	swap_top(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_top(a);
	swap_top(b);
	ft_putstr_fd("ss\n", 1);
}