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

void	ra(t_stack **a)
{
	rotate_top(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate_top(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_top(a);
	rotate_top(b);
	ft_putstr_fd("rr\n", 1);
}

void	print_stack(t_stack *x)
{

	while (x != NULL)
	{
		ft_putnbr_fd(x->content, 1);
		ft_putchar_fd(' ', 1);
		x = x->next;
	}
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	int	array[] = {5, 3, 1, 0};
	int	array_size;
	t_stack *a;
	t_stack *b;

	array_size = 4;
	a = build_stack(array, array_size);
	b = NULL;

	print_stack(a);
	sa(&a);
	print_stack(a);
	sb(&b);
	print_stack(b);
	ss(&a, &b);
	print_stack(a);
	print_stack(b);

	ra(&a);
	print_stack(a);
	rb(&b);
	print_stack(b);
	rr(&a, &b);
	print_stack(a);
	print_stack(b);

	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}