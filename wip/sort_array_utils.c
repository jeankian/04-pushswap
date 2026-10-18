/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:37:36 by xin-jili          #+#    #+#             */
/*   Updated: 2026/10/10 12:37:37 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_values(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

static int	partition(int *array, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = array[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot_value)
		{
			swap_values(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	swap_values(&array[i], &array[high]);
	return (i);
}

void	quicksort_array(int *array, int low, int high)
{
	int	pivot_index;

	if (low > high)
		return ;
	pivot_index = partition(array, low, high);
	quicksort_array(array, low, pivot_index - 1);
	quicksort_array(array, pivot_index + 1, high);
}
