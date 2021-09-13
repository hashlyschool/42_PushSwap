#include "push_swap.h"

char	stack_a_is_sort(t_elem *a)
{
	int		max;
	size_t	len;

	len = len_stack(a);
	if (len == 2)
	{
		if (a->var < a->prev->var)
			return (1);
	}
	else if (len == 3)
	{
		max = a->var;
		while (--len)
		{
			a = a->next;
			if (a->var > max)
				max = a->var;
		}
		while (a->var != max)
			a = a->next;
		if (a->next->var > a->prev->var)
			return (1);
	}
	return (0);
}

void	mini_predsort(t_elem **a, t_elem **b)
{
	size_t	len;

	len = len_stack(*a);
	while (len-- - 3)
		push(a, b, 1);
	if (!stack_a_is_sort(*a))
		swap(a, 1);
}
