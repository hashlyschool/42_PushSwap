#include "push_swap.h"

int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}

void	find_min_score2(int *score, t_elem *temp)
{
	int	b;

	if (temp->score_a * temp->score_b > 0)
	{
		*score = ft_abs(temp->score_a);
		b = ft_abs(temp->score_b);
		if (b > *score)
			*score = b;
	}
	else
		*score = ft_abs(temp->score_a) + ft_abs(temp->score_b);
}

t_elem	*find_min_score(t_elem **b)
{
	int		score;
	int		score_min;
	t_elem	*temp;
	t_elem	*min;

	temp = *b;
	min = *b;
	find_min_score2(&score, temp);
	score_min = score;
	temp = temp->next;
	while (temp != *b)
	{
		find_min_score2(&score, temp);
		if (score < score_min)
		{
			min = temp;
			score_min = score;
		}
		temp = temp->next;
	}
	return (min);
}

void	operation2(t_elem **a, t_elem **b, t_elem *min)
{
	if (min->score_a > 0)
	{
		rotate(a, 1);
		min->score_a--;
	}
	else if (min->score_a < 0)
	{
		rev_rotate(a, 1);
		min->score_a++;
	}
	else if (min->score_b > 0)
	{
		rotate(b, 1);
		min->score_b--;
	}
	else if (min->score_b < 0)
	{
		rev_rotate(b, 1);
		min->score_b++;
	}
}

void	operation(t_elem **a, t_elem **b)
{
	t_elem	*min;

	min = find_min_score(b);
	while (min->score_a || min->score_b)
	{
		if (min->score_a * min->score_b > 0)
		{
			if (min->score_a > 0)
			{
				rr(a, b, 1);
				min->score_a--;
				min->score_b--;
			}
			else
			{
				rev_rr(a, b, 1);
				min->score_a++;
				min->score_b++;
			}
		}
		else
			operation2(a, b, min);
	}
}
