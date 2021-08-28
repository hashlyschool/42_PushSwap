#include "push_swap.h"

char	check_flag_one_two(t_elem *temp, char *flag, t_elem *temp_start)
{
	if (*flag == 1)
	{
		if (temp->next->var < temp_start->var && temp->next->var < temp->var)
			return (1);
		else if (temp->next->var > temp_start->var)
		{
			*flag = 2;
			return (1);
		}
	}
	else if (*flag == 2)
	{
		if (temp->next->var < temp->var && temp->next->var > temp_start->var)
			return (1);
	}
	*flag = 0;
	return (0);
}

char	condition_1(t_elem *temp, char *flag, t_elem *temp_start)
{
	if (*flag == 1 || *flag == 2)
		return (check_flag_one_two(temp, flag, temp_start));
	else if (*flag == -1)
	{
		if (temp->next->var > temp_start->var && temp->next->var > temp->var)
			return (1);
		else if (temp->next->var < temp_start->var)
		{
			*flag = -2;
			return (1);
		}
	}
	else if (*flag == -2)
	{
		if (temp->next->var > temp->var && temp->next->var < temp_start->var)
			return (1);
	}
	*flag = 0;
	return (0);
}

void	go_circle(t_elem *a, t_elem **start, t_elem **end, size_t *len)
{
	t_elem	*temp;
	t_elem	*end_temp;
	size_t	len_temp;
	char	flag;

	temp = a;
	len_temp = 1;
	flag = 1;
	if (a->next->var > a->var)
		flag = -1;
	while (flag && temp->next != a)
	{
		if (condition_1(temp, &flag, a))
		{
			len_temp++;
			end_temp = temp->next;
		}
		temp = temp->next;
	}
	if (len_temp > *len)
	{
		*len = len_temp;
		*start = a;
		*end = end_temp;
	}
}

/*Функция принимает стек 'а', ссылки на стартовый и конечный элемент стека, которые нужно заполнить.
Функция ищет в стеке 'а' максимальную условно отформатированную последовательность элементов,
записывает в входные переменные 'start' и 'end' ссылки на нужные элементы стека 'a'*/
void	find_max_substack(t_elem **a, t_elem **start, t_elem **end)
{
	size_t	len;
	t_elem	**temp;

	temp = a;
	len = 0;
	while ((*temp)->next != *a)
	{
		go_circle(*temp, start, end, &len);
		temp = &((*temp)->next);
	}
	go_circle(*temp, start, end, &len);
	return ;
}

void	predsort(t_elem **a, t_elem **b)
{
	t_elem	*start;
	t_elem	*end;

	find_max_substack(a, &start, &end);
	ft_putstr_fd("start = ", 1);
	ft_putnbr_fd(start->var, 1);
	ft_putstr_fd("\nend = ", 1);
	ft_putnbr_fd(end->var, 1);
	ft_putstr_fd("\n", 1);
	push_elem_in_stack_a(a, b, start, end);
}
