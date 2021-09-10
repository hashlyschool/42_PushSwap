#include "push_swap.h"

int		find_pos(t_elem **b, int var)
{
	int		score;
	int		score_rev;
	t_elem	*temp;

	score = 0;
	score_rev = 0;
	temp = *b;
	while (temp->var != var)
	{
		score++;
		temp = temp->prev;
	}
	temp = *b;
	while (temp->var != var && -score_rev < score + 2)
	{
		score_rev--;
		temp = temp->next;
	}
	if (score > score_rev * -1)
		return score_rev;
	else
		return score;
}

void	find_scores(t_elem **a, t_elem **b)
{
	t_elem	*temp;

	temp = *b;
	temp->score_a = find_q_rev(a, temp->var);
	temp->score_b = find_pos(b, temp->var);
	temp = temp->next;
	while (temp != *b)
	{
		temp->score_a = find_q_rev(a, temp->var);
		temp->score_b = find_pos(b, temp->var);
		temp = temp->next;
	}
}

void	zero_scores(t_elem **b)
{
	t_elem	*temp;

	temp = *b;
	temp->score_a = 0;
	temp->score_b = 0;
	temp = temp->next;
	while (temp != *b)
	{
		temp->score_a = 0;
		temp->score_b = 0;
		temp = temp->next;
	}
}

void	finish_sort(t_elem **a)
{
	while (!((*a)->middle < 3 && (*a)->next->middle > 1))
	{
		if ((*a)->middle < 3)
			rev_rotate(a);
		else
			rotate(a);
	}
}
