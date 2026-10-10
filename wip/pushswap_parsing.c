#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	res;

	n = 1;
	res = 0;
	while ((*str >= '\t' && *str <= '\r') || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -n;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * n);
}

void	*ft_calloc(size_t elnum, size_t elsize)
{
	unsigned char	*ptr;
	size_t			total;
	size_t			i;

	if (elnum != 0 && elsize > (SIZE_MAX / elnum))
		return (NULL);
	if (elnum == 0 || elsize == 0)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	total = elnum * elsize;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (ft_calloc(1, 1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = malloc((i + j + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

size_t	wordcount(const char *s, char c)
{
	size_t	wcount;
	size_t	i;

	wcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			wcount++;
		i++;
	}
	return (wcount);
}

char	*wordptr(const char *s, char c, size_t start)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	while (s[start + i] && s[start + i] != c)
		i++;
	len = i;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	leak_cleanup(char **ptrs, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(ptrs[i]);
		i++;
	}
	free(ptrs);
}

char	**ft_split(const char *s, char c)
{
	char	**ptrs;
	size_t	i;
	size_t	j;

	ptrs = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (ptrs == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			ptrs[j] = wordptr(s, c, i);
			if (ptrs[j] == NULL)
			{
				leak_cleanup(ptrs, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	ptrs[j] = NULL;
	return (ptrs);
}


/* ************************************************************************** */

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

int *parse_multi_arg(int argc, char **argv, int index, int *array_size)
{
	int *array;

	*array_size = argc - index;
	array = str_to_int_array(argv + index, *array_size);
	return (array);
}

int *parse_single_arg(char *argv, int *array_size)
{
	char **numstr;
	int *array;
	int	i;

	numstr = ft_split(argv, ' ');
	if (!numstr)
		return (NULL);
	i = 0;
	while (numstr[i])
		i++;
	if (i == 0)
	{
		cleanup_tree(numstr);
		return (NULL);
	}
	*array_size = i;
	array = str_to_int_array(numstr, *array_size);
	cleanup_tree(numstr);
	return (array);
}

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


int *parsing(int argc, char **argv, int index)
{
	int *array;
	int array_size;

	array_size = 0;
	if (argv[index + 1] == NULL)
		array = parse_single_arg(argv[index], &array_size);
	else
		array = parse_multi_arg(argc, argv, index, &array_size);
	if (array == NULL || array_size == 0 || !is_not_dup(array, array_size))
	{
		free(array);
		return (NULL);
	}
	return (array);
}

int	process_args(int argc, char **argv)
{
	int i;
	int	*array;

	if (argc < 2)
		return (1);
	i = 1;
	while (is_flag(argv[i]))
	{
		i++;
		if (argv[i] == NULL)
			return (1);
	}
	array = parsing(argc, argv, i);
	if (!array)
		return (0);
	free(array);
	return (1);
}

int	main(int argc, char **argv)
{
	if (process_args(argc, argv) == 1)
		ft_putstr_fd("Parsing successful\n", 1);
	else
		ft_putstr_fd("Parsing failed\n", 2);

	return(0);
}