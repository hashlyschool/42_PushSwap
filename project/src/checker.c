#include "push_swap.h"

void	checker_operation(t_elem **a, t_elem **b, char *line)
{
	if (line && ft_strlen(line))
	{
		if (!ft_strncmp(line, "sa", ft_strlen(line)))
			swap(a, 0);
		else if (!ft_strncmp(line, "sb", ft_strlen(line)))
			swap(b, 0);
		else if (!ft_strncmp(line, "ss", ft_strlen(line)))
			ss(a, b, 0);
		else if (!ft_strncmp(line, "pa", ft_strlen(line)))
			push(b, a, 0);
		else if (!ft_strncmp(line, "pb", ft_strlen(line)))
			push(a, b, 0);
		else if (!ft_strncmp(line, "ra", ft_strlen(line)))
			rotate(a, 0);
		else if (!ft_strncmp(line, "rb", ft_strlen(line)))
			rotate(b, 0);
		else if (!ft_strncmp(line, "rr", ft_strlen(line)))
			rr(a, b, 0);
		else if (!ft_strncmp(line, "rra", ft_strlen(line)))
			rev_rotate(a, 0);
		else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
			rev_rotate(b, 0);
		else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
			rev_rr(a, b, 0);
	}
}

void	stack_is_sort_shecker(t_elem *a, t_elem *b)
{
	t_elem	*temp1;
	t_elem	*temp2;
	char	sort;

	temp1 = a;
	sort = 0;
	if (b)
	{
		if (a)
			ft_error_malloc_not_exit(a, "");
		ft_error_malloc(b, "KO\n");
	}
	while (temp1 != a->next)
	{
		temp2 = temp1->prev;
		if (temp1->var > temp2->var)
		{
			ft_error_malloc_not_exit(a, "");
			ft_error_malloc(b, "KO\n");
		}
		temp1 = temp1->prev;
	}
	ft_error_malloc(a, "OK\n");
}

int	main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;
	char	*line;
	int		i;

	check_errors(argc, argv);
	create_lists(&a, &b, argc, argv);
	check_doubles(a);
	i = get_next_line(0, &line);
	while (i > 0 && ft_strlen(line))
	{
		checker_operation(&a, &b, line);
		free(line);
		i = get_next_line(0, &line);
	}
	checker_operation(&a, &b, line);
	free(line);
	stack_is_sort_shecker(a, b);
}
