#include <stddef.h>
#include <unistd.h>


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

/* ************************************************************************** */

int is_integer(char *arg)
{
	size_t i;

	if (arg == NULL || *arg == '\0')
		return (0);
	i = 0;
	if ((arg[i] == '-' || arg[i] == '+') && (ft_isdigit(arg[i + 1])))
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int is_flag(char *arg)
{
	size_t len;

	len = ft_strlen(arg) + 1;
	if (ft_strncmp(arg, "--simple", len) == 0 || 
		ft_strncmp(arg, "--medium", len) == 0 || 
		ft_strncmp(arg, "--complex", len) == 0 || 
		ft_strncmp(arg, "--adaptive", len) == 0 || 
		ft_strncmp(arg, "--bench", len) == 0)
		return (1);
	return (0);
}

int	parse(int argc, char **argv)
{
	int i;

	if (argc < 2)
		return (0);

	i = 1;
	while (is_flag(argv[i]))
	{
		i++;
		if (argv[i] == NULL)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
	}
	while (argv[i])
	{
		if (!is_integer(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (parse(argc, argv))
		ft_putstr_fd("Parsing successful\n", 1);
	else
		ft_putstr_fd("Parsing failed\n", 2);

	return(0);
}