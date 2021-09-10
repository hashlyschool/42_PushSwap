#include "push_swap.h"

void	sort_array(int *num, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (num[j] < num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

/*
возвращает 1, если елемент a , входит в последовательность
возвращает 0, если элемент не входит в последовательность
*/
char	check_elem_in_substack(t_elem *a, t_elem *start, t_elem *end)
{
	t_elem	*temp;

	temp = a;
	if (temp == start || temp == end)
		return (1);
	temp = temp->next;
	while (temp->next != a)
	{
		if (temp == start)
			return (0);
		else if (temp == end)
			return (1);
		temp = temp->next;
	}
	return (0);
}

char	stack_b_is_sort(t_elem *b)
{
	if (!b)
		return (1);
	else if (b == b->next)
		return (1);
	else if (b->middle == 1 && b->prev->middle > 1)
		return (0);
	else
		return (1); //если следующий тоже 1??
	/*
	t_elem	*temp;

	temp = b;
	while (temp->prev != b)
	{
		if (temp->middle >= temp->prev->middle)
			temp = temp->prev;
		else
			return (0);
	}
	return (1);
	*/
}

//возвращает 1, если выгоднее использовать ra (т.е. двигаясь вперед быстрее
//достигается конец последовательности, чем в обратном направлении)
// Или возвращает 0, если назад двигаться выгоднее
char	find_steps(t_elem *a, t_elem *start, t_elem *end)
{
	size_t	forward;
	size_t	back;
	t_elem *temp;

	forward = 0;
	back = 0;
	temp = a;
	while (temp != start)
	{
		temp = temp->prev;
		back++;
	}
	temp = a;
	while (temp != end)
	{
		temp = temp->next;
		forward++;
	}
	if (forward > back)
		return (1);
	return (0);
}

/*
Функция должна анализировать стеки 'a' and 'b' и определять код необходимой операции по правилу:
return:
		1 - pb
		2 - ra
		3 - rb
		4 - rr
		5 - rra
		6 - rrb
		7 - rrr
*/
char	define_operation(t_elem *a, t_elem *b, t_elem *start, t_elem *end)
{
	if (!check_elem_in_substack(a, start, end))
	{
		if (stack_b_is_sort(b))
			return (1);
		else
			return (3);
	}
	else //входит в последовательность
	{
		if (start->prev == end)
		{
			if (!stack_b_is_sort(b))
				return (3);
			else
				return (0);
		}
		else if (find_steps(a, start, end)) //надо написать поиск как лучше сделать: реверсить по одной снизу или всю последовательность бахнуть вниз и потом пушить остатки вниз
			return (2);
		else
			return (5);
	}
}
