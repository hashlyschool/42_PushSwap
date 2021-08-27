#include "push_swap.h"

char	condition_1(t_elem *temp, char *flag)
{
	if (*flag == 1)
	{
		if (temp->var < temp->next->var)
			(*flag)++;
		return (1);
	}
	else if (*flag == 2 && (temp->var < temp->next->var))
		return (1);
	else if (*flag == -1)
	{
		if (temp->var > temp->next->var)
			(*flag)--;
		return (1);
	}
	else if (*flag == -2 && (temp->var > temp->next->var))
		return (1);
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
	if (a->var < a->prev->var)
		flag = -1;
	ft_putstr_fd("tut22\n", 1);
	while (flag && temp->next != a)
	{
		if (condition_1(temp, &flag))
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
		ft_putstr_fd("_out_go_circle\n", 1);
		temp = &((*temp)->next);
	}
	go_circle(*temp, start, end, &len);
	ft_putstr_fd("start = ", 1);
	ft_putnbr_fd((*start)->var, 1);
	ft_putstr_fd("\nend = ", 1);
	ft_putnbr_fd((*end)->var, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

/*
Функция принимает ссылки на стек 'a', стек 'b' и ссылки на начало и конец последовательности элементов.
Ф-я должна переносит в стек 'b' все элементы, кроме max, min и входной последовательности.
правило переноса в стек 'b': элементы больше среднего, средний элемент, элементы меньше среднего.
*/
void	push_elem_in_stack_a(t_elem **a, t_elem **b, t_elem *start, t_elem *end)
{
	/*find_max();
	find_min();
	find_mid();*/
	a = 0;
	b = 0;
	start = 0;
	end = 0;
	return ;
}

void	predsort(t_elem **a, t_elem **b)
{
	t_elem	*start;
	t_elem	*end;

	find_max_substack(a, &start, &end);
	ft_putstr_fd("tut\n", 1);
	push_elem_in_stack_a(a, b, start, end);
}
