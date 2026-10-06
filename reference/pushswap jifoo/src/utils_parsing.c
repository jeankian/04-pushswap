/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:53:25 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/03 17:00:44 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_to_int(const char *str, int *out)
{
	int		i;
	int		sign;
	long	sum;

	i = 0;
	sum = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		sum = sum * 10 + (str[i++] - '0');
		if ((sign * sum > INT_MAX) || (sign * sum < INT_MIN))
			return (0);
	}
	*out = (int)(sum * sign);
	return (1);
}

static void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

static int	*fill_arr(char **tokens, int count)
{
	int	*arr;
	int	i;
	int	num;

	arr = malloc(sizeof(int) * (count + 1));
	if (!arr)
		exit (1);
	i = 0;
	while (tokens[i])
	{
		if (!str_to_int(tokens[i], &num))
		{
			free_tokens(tokens);
			free(arr);
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		arr[i] = num;
		i++;
	}
	return (arr);
}

int	*parse_one_arg(char *str, int *arr_count)
{
	char	**tokens;
	int		*arr;
	int		count;

	tokens = ft_split(str, ' ');
	if (!tokens)
	{
		*arr_count = 0;
		return (NULL);
	}
	count = 0;
	while (tokens[count])
		count++;
	arr = fill_arr(tokens, count);
	free_tokens(tokens);
	*arr_count = count;
	return (arr);
}

int	*parse_multi_args(int argc, char **argv, int *arr_count)
{
	int	*arr;
	int	num;
	int	j;

	arr = malloc(sizeof(int) * argc);
	if (!arr)
		exit (1);
	j = 1;
	while (j < argc)
	{
		if (!str_to_int(argv[j], &num))
		{
			free(arr);
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		arr[j - 1] = num;
		j++;
	}
	*arr_count = argc - 1;
	return (arr);
}
