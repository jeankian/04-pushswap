#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>

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

void	*cleanup_split(char **split_args)
{
	size_t	i;

	if (split_args == NULL)
		return (NULL);
	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
	return (NULL);
}

int	is_not_dup(char **argv, int i)
{
	int	current;
	int	start;

	current = ft_atoi(argv[i]);
	start = 0;
	while (start < i)
	{
		if (ft_atoi(argv[start]) == current)
			return (0);
		start++;
	}
	return (1);
}

int	is_int_range(char *argv)
{
	long long	res;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (argv[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (argv[i] == '+')
		i++;
	res = 0;
	while (argv[i])
	{
		res = res * 10 + (argv[i] - '0');
		if (res * sign < INT_MIN || res * sign > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int is_digit(char *argv)
{
	size_t i;

	if (argv == NULL || *argv == '\0')
		return (0);
	i = 0;
	if ((argv[i] == '-' || argv[i] == '+') && (ft_isdigit(argv[i + 1])))
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
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

int	parse(int argvc, char **argv)
{
	int i;
	char *joined_args;
	char *new;
	char *tmp;
	char **split_args;

	if (argvc < 2)
		return (1);
	
	i = 1;
	while (is_flag(argv[i]))
	{
		i++;
		if (argv[i] == NULL)
				return (1);
	}

	joined_args = ft_calloc(1, 1);
	if (joined_args == NULL)
		return (0);
	
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (0);
		tmp = ft_strjoin(argv[i], " ");
		if (tmp == NULL)
		{
			free(joined_args);
			return (0);
		}
		new = ft_strjoin(joined_args, tmp);
		if (new == NULL)
		{
			free(joined_args);
			free(tmp);
			return (0);
		}
		free(joined_args);
		free(tmp);
		joined_args = new;
		i++;
	}

	split_args = ft_split(joined_args, ' ');
	free(joined_args);
	if (split_args == NULL)
		return (0);

	if (split_args[0] == NULL)
	{
		cleanup_split(split_args);
		return (0);
	}

	i = 0;
	while (split_args[i])
	{
		if (!is_digit(split_args[i]) || !is_int_range(split_args[i]) || !is_not_dup(split_args, i))
		{
			cleanup_split(split_args);
			return (0);
		}
		i++;
	}
	cleanup_split(split_args);
	return (1);
}

int	main(int argvc, char **argv)
{
	if (parse(argvc, argv) == 1)
		ft_putstr_fd("Parsing successful\n", 1);
	else
		ft_putstr_fd("Parsing failed\n", 2);

	return(0);
}