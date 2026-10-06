/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_and_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:20:21 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/03 16:30:12 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *arr, int arr_count)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < arr_count)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	*sort_array(int *arr, int arr_count)
{
	int	i;
	int	*sorted_arr;

	sorted_arr = malloc(sizeof(int) * arr_count);
	if (!sorted_arr)
		return (NULL);
	i = 0;
	while (i < arr_count)
	{
		sorted_arr[i] = arr[i];
		i++;
	}
	insertion_sort(sorted_arr, arr_count);
	return (sorted_arr);
}

static int	find_index(int *sorted_arr, int value, int arr_count)
{
	int	i;

	i = 0;
	while (i < arr_count)
	{
		if (value == sorted_arr[i])
			return (i);
		i++;
	}
	return (-1);
}

t_stack	*index_stack(t_stack *stack, int *arr, int arr_count)
{
	t_stack	*current;
	int		*sorted_arr;

	if (!stack)
		return (NULL);
	current = stack;
	sorted_arr = sort_array(arr, arr_count);
	if (!sorted_arr)
		return (free(sorted_arr), NULL);
	while (current != NULL)
	{
		current -> index = find_index(sorted_arr,
				*(int *)current -> content, arr_count);
		if (current -> index == -1)
			return (free(sorted_arr), NULL);
		current = current -> next;
	}
	free(sorted_arr);
	return (stack);
}
