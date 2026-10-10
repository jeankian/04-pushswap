

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