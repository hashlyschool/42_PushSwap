#include "push_swap.h"

char	condition_1(t_elem *temp, char *flag, t_elem *temp_start)
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

void	go_circle(t_elem *a, t_elem **start, t_elem **end, size_t *len)
{
	t_elem	*temp;
	t_elem	*end_temp;
	size_t	len_temp;
	char	flag;

	temp = a;
	len_temp = 1;
	flag = 0;
	if (a->next->var < a->var)
		flag = 1;
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

/*
	Функция принимает стек 'а', ссылки на стартовый и конечный элемент
стека, которые нужно заполнить. Функция ищет в стеке 'а' максимальную
условно отформатированную последовательность элементов, записывает в
входные переменные 'start' и 'end' ссылки на нужные элементы стека 'a'
*/
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

/*
Эта функция находит средний элемент (не среднее арифметическое!)
и делает в нужном элементе списка операцию
Больше среднего - 'temp->middle = 3'
средний - 'temp->middle = 2;'
Меньше среднего - 'temp->middle = 1'
*/
void	find_mid(t_elem **a)
{
	size_t	len_arr;
	int		*arr;
	size_t	i;

	i = 0;
	len_arr = len_stack(*a);
	arr = (int *)malloc(sizeof(int) * len_arr);
	while (i < len_arr)
	{
		arr[i] = (*a)->var;
		i++;
		*a = (*a)->prev;
	}
	sort_array(arr, len_arr);
	while ((*a)->middle == 0)
	{
		if ((*a)->var > arr[len_arr / 2])
			(*a)->middle = 3;
		else if ((*a)->var == arr[len_arr / 2])
			(*a)->middle = 2;
		else
			(*a)->middle = 1;
		*a = (*a)->prev;
	}
	free(arr);
}

/*
Функция принимает ссылки на стек 'a', стек 'b'
Ф-я должна переносит в стек 'b' все элементы, последовательности,
найденной в функции 'find_max_substack'. Правило переноса в
стек 'b': элементы больше среднего и средний элемент
и элементы меньше среднего.
*/
void	predsort(t_elem **a, t_elem **b)
{
	t_elem	*start;
	t_elem	*end;
	char	operation;

	find_max_substack(a, &start, &end);
	operation = define_operation(*a, *b, start, end);
	while (operation)
	{
		if (operation == 1)
			push(a, b, 1);
		else if (operation == 2)
			rotate(a, 1);
		else if (operation == 3)
			rotate(b, 1);
		else if (operation == 4)
			rr(a, b, 1);
		else if (operation == 5)
			rev_rotate(a, 1);
		else if (operation == 6)
			rev_rotate(b, 1);
		else if (operation == 7)
			rev_rr(a, b, 1);
		operation = define_operation(*a, *b, start, end);
	}
}
