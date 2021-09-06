#include "push_swap.h"

int		ft_max(a, b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		ft_abs(int a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}

t_elem	*find_min_score(t_elem **b)
{
	int		score;
	int		score_min;
	t_elem	*temp;
	t_elem	*min;

	temp = *b;
	min = *b;
	if (temp->score_a * temp->score_b > 0)
		score = ft_max(temp->score_a, temp->score_b);
	else
		score = temp->score_a - temp->score_b;
	score_min = score;
	temp = temp->next;
	while (temp != *b)
	{
		if (temp->score_a * temp->score_b > 0)
			score = ft_max(temp->score_a, temp->score_b);
		else
			score = ft_abs(temp->score_a) + ft_abs(temp->score_b);
		if (score < score_min)
		{
			min = temp;
			score_min = score;
		}
		temp = temp->next;
	}
	return (min);
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
				rr(a, b);
				min->score_a--;
				min->score_b--;
			}
			else
			{
				rev_rr(a, b);
				min->score_a++;
				min->score_b++;
			}
		}
		else if (min->score_a > 0)
		{
			rotate(a);
			min->score_a--;
		}
		else if (min->score_a < 0)
		{
			rev_rotate(a);
			min->score_a++;
		}
		else if (min->score_b > 0)
		{
			rotate(b);
			min->score_b--;
		}
		else if (min->score_b < 0)
		{
			rev_rotate(b);
			min->score_b++;
		}
	}
}

void	sort_stacks(t_elem **a, t_elem **b)
{
	while (*b)
	{
		find_scores(a, b); //найти скоры
		operation(a, b); //реверсы по скорам
		zero_scores(b);
		push(b, a); // пушим из б в а
	}
	finish_sort(a); //реверсы до победного
}
