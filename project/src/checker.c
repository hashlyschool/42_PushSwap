#include "push_swap.h"

void	checker_operation(t_elem **a, t_elem **b, char *line)
{
	if (line && ft_strlen(line))
	{
		if (!ft_strncmp(line, "sa", ft_strlen(line)))
			swap(a);
		else if (!ft_strncmp(line, "sb", ft_strlen(line)))
			swap(b);
		else if (!ft_strncmp(line, "ss", ft_strlen(line)))
			ss(a, b);
		else if (!ft_strncmp(line, "pa", ft_strlen(line)))
			push(b, a);
		else if (!ft_strncmp(line, "pb", ft_strlen(line)))
			push(a, b);
		else if (!ft_strncmp(line, "ra", ft_strlen(line)))
			rotate(a);
		else if (!ft_strncmp(line, "rb", ft_strlen(line)))
			rotate(b);
		else if (!ft_strncmp(line, "rr", ft_strlen(line)))
			rr(a, b);
		else if (!ft_strncmp(line, "rra", ft_strlen(line)))
			rev_rotate(a);
		else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
			rev_rotate(b);
		else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
			rev_rr(a, b);
	}
}

void	stack_is_sort_shecker(t_elem *a, t_elem *b)
{
	t_elem	*temp1, *temp2;
	char	sort;

	temp1 = a;
	sort = 0;
	if (b)
	{
		if (a)
			ft_error_malloc_not_exit(a, "");
		ft_error_malloc(b, "KO\n");
	}
	while(temp1 != a->next)
	{
		temp2 = temp1->prev;
		if (temp1->var > temp2->var)
		{
			ft_error_malloc_not_exit(a, "");
			ft_error_malloc(b, "KO\n");
		} //stack is not sort\n
		temp1 = temp1->prev;
	}
	ft_error_malloc(a, "OK\n"); //"stack is sort\n"
}

int		main(int argc, char **argv)
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
	//все операции норм написаны и успешно выполнены
	stack_is_sort_shecker(a, b);

	//чтение элементов из кучи аргументов и одного
	//проверка на повторы??
	//чтение операций и выполнение их
	//проверка на сортированность (ОК или КО)
	//stack_is_sort(a); Сортировка стека и очистка одного или 2 стеков
	//вывод ОК или КО
}
