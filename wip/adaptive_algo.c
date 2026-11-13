#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

int	count_wrong_pairs(t_data *data)
{
	t_stack	*ptr_outer;
	t_stack	*ptr_inner;
	int		wrong_pairs;

	ptr_outer = data->stack_a;

	if (ptr_outer == NULL)
		return (0);
	wrong_pairs = 0;

	while (ptr_outer->next != NULL)
	{
		ptr_inner = ptr_outer->next;
		while (ptr_inner != NULL)
		{
			if (ptr_outer->index > ptr_inner->index)
				wrong_pairs++;
			ptr_inner = ptr_inner->next;
		}
		ptr_outer = ptr_outer->next;
	}
	return (wrong_pairs);
}

void	compute_disorder_pct(t_data *data)
{
	int	stack_a_size;
	int	wrong_pairs;
	int	total_pairs;
	int	disorder_pct;

	stack_a_size = get_stack_size(data->stack_a);
	if (stack_a_size <= 1)
		return ;
	wrong_pairs = count_wrong_pairs(data);
	total_pairs = stack_a_size * (stack_a_size - 1) / 2;
	disorder_pct = wrong_pairs * 10000 / total_pairs;
	data->disorder_pct = disorder_pct;
}

void	set_adaptive_strategy_name(t_data *data)
{
	if (data->disorder_pct < 2000)
		data->strategy_name = "Adaptive (Simple) / O(n^2)";
	else if (data->disorder_pct < 5000)
		data->strategy_name = "Adaptive (Medium) / O(n*sqrt(n))";
	else
		data->strategy_name = "Adaptive (Complex) / O(n log n)";
}

void	pick_adaptive_algorithm(t_data *data)
{
	int	stack_a_size;

	set_adaptive_strategy_name(data);
	stack_a_size = get_stack_size(data->stack_a);
	if (data->disorder_pct == 0)
		return ;
	else if (stack_a_size == 2)
		ra(data);
	// else if (stack_a_size == 3)
	// 	sort_three(data);
	// else if (stack_a_size == 4)
	// 	sort_four(data);
	// else if (stack_a_size == 5)
	// 	sort_five(data);
	else if (data->disorder_pct < 2000)
		// sort_simple(data);
		ft_printf("sort_simple\n");
	else if (data->disorder_pct < 5000)
	{
		sort_medium(data);
		ft_printf("sorted_medium\n");
	}
	else
		// sort_complex(data);
		ft_printf("sort_complex\n");
}

void	pick_algorithm(t_data *data)
{
	if (data->strategy == 1)
	{
		data->strategy_name = "Simple / O(n^2)";
		// sort_simple(data);
	}
	else if (data->strategy == 2)
	{
		data->strategy_name = "Medium / O(n*sqrt(n))";
		sort_medium(data);
	}
	else if (data->strategy == 3)
	{
		data->strategy_name = "Complex / O(n log n)";
		// sort_complex(data);
	}
	else
		pick_adaptive_algorithm(data);
}

void	print_bench(t_data *data)
{
	int	d;
	int	m;

	if (data->bench == 1)
	{
		ft_putstr_fd("[bench] disorder: ", 2);
		d = data->disorder_pct / 100;
		ft_putnbr_fd(d, 2);
		ft_putchar_fd('.', 2);
		m = data->disorder_pct % 100;
		if (m < 10)
			ft_putchar_fd('0', 2);
		ft_putnbr_fd(m, 2);
		ft_putchar_fd('%', 2);
		ft_putchar_fd('\n', 2);
	}
}

// cc42 adaptive_algo.c operations_push.c operations_swap.c operations_rotate.c operations_reverse_rotate.c create_index_stacks.c create_stacks_utils.c medium_algo.c sort_array_utils.c -I ./printf -I ./libft -L ./printf -L ./libft -lftprintf -lft -o asdf

int	main(void)
{
	int	array [] = {1, 23, 0, 5, 3, 2, 6, 4, 7};
	// int	array [] = {1, 7};
	t_data	data;
	t_stack *ptr;
	// int	wrong_pairs;

	ft_bzero(&data,sizeof(data));
	data.bench = 1;
	data.stack_a = build_stack(array, 9);
	index_stack(data.stack_a, array, 9);
	// data.stack_a = build_stack(array, 2);
	// index_stack(data.stack_a, array, 2);

	ptr = data.stack_a;
	ft_printf("stack a:");
	while(ptr != NULL)
	{
		ft_printf("%d, ", ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");

	// wrong_pairs = count_wrong_pairs(&data);
	// ft_printf("%d", wrong_pairs);

	compute_disorder_pct(&data);

	ft_printf("%d\n", data.disorder_pct);

	pick_algorithm(&data);


	ptr = data.stack_a;
	ft_printf("stack a:");
	while(ptr != NULL)
	{
		ft_printf("%d, ", ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");

	ft_printf("%s\n", data.strategy_name);
	print_bench(&data);

	ft_stack_clear(&data.stack_a);
	ft_stack_clear(&data.stack_b);
	return (0);
}
