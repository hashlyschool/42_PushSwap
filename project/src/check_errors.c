#include "push_swap.h"

void	argv_is_numeric(char **argv)
{
	int	i;
	int	a;
	int first;

	i = 1;
	while (argv[i] != NULL)
	{
		a = 0;
		first = 1;
		while (argv[i][a])
		{
			if (first && argv[i][a] == '-' )
			{
				first = 0;
				a++;
			}
			else if (!ft_isdigit((int)argv[i][a]))
				ft_error_arg("Error\n");
			a++;
		}
		i++;
	}
}

int		max_int(const char *str)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (sign == -1)
	{
		if (result - 1 > INT_MAX)
			return (1);
	}
	else if (result > INT_MAX)
		return (1);
	return (0);
}

void	argv_is_int(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (max_int(argv[i]) == 1)
			ft_error_arg("Error\n");
		i++;
	}
}


void	check_errors(int argc, char **argv)
{
	if (argc < 2)
		exit(0);
	argv_is_numeric(argv);
	argv_is_int(argv);
}

void	check_doubles(t_elem *lst)
{
	t_elem	*temp, *temp2;

	temp = lst;
	while (temp != lst->next)
	{
		temp2 = temp;
		while (temp2 != temp->next)
		{
			if (temp->var == temp2->prev->var)
				ft_error_malloc(lst, "Error, doubles element\n");
			temp2 = temp2->prev;
		}
		temp = temp->prev;
	}
}
