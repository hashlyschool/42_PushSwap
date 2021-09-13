#include "push_swap.h"

void	sort_stacks(t_elem **a, t_elem **b)
{
	while (*b)
	{
		find_scores(a, b);
		operation(a, b);
		zero_scores(b);
		push(b, a, 1);
	}
	finish_sort(a);
}
