#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

int is_flag(char *argv)
{
	size_t len;

	len = ft_strlen(argv) + 1;
	if (ft_strncmp(argv, "--simple", len) == 0 || 
		ft_strncmp(argv, "--medium", len) == 0 || 
		ft_strncmp(argv, "--complex", len) == 0 || 
		ft_strncmp(argv, "--adaptive", len) == 0 || 
		ft_strncmp(argv, "--bench", len) == 0)
		return (1);
	return (0);
}

void	*cleanup_tree(char **tree)
{
	size_t	i;

	if (tree == NULL)
		return (NULL);
	i = 0;
	while (tree[i])
	{
		free(tree[i]);
		i++;
	}
	free(tree);
	return (NULL);
}

int	is_int(char *argv)
{
	long long	num;
	int	i;
	int	sign;

	if (argv == NULL || *argv == '\0')
		return (0);
	i = 0;
	sign = 1;
	if ((argv[i] == '-' || argv[i] == '+') && (ft_isdigit(argv[i + 1])))
	{
		if (argv[i] == '-')
			sign = -sign;
		i++;
	}
	num = 0;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		num = num * 10 + (argv[i] - '0');
		if (num * sign < INT_MIN || num * sign > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int *str_to_int_array(char **numstr, int array_size)
{
	int *array;
	int	i;

	array = malloc(array_size * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < array_size)
	{
		if (!is_int(numstr[i]))
		{
			free(array);
			return (NULL);
		}
		array[i] = ft_atoi(numstr[i]);
		i++;
	}
	return (array);
}

int	is_not_dup(int *array, int array_size)
{
	int	i;
	int	j;

	i = 1;
	while (i < array_size)
	{
		j = 0;
		while (j < i)
		{
			if (array[i] != array[j])
				j++;
			else
			return (0);
		}
		i++;
	}
	return (1);
}
