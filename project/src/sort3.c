#include "push_swap.h"

char	find_flag(t_elem *a, int var)
{
	t_elem	*temp;
	char	big;
	char	small;

	big = 0;
	small = 0;
	temp = a;
	if (var > temp->var)
		big = 1;
	else
		small = 1;
	temp = temp->next;
	while (temp != a)
	{
		if (var > temp->var)
			big = 1;
		else
			small = 1;
		temp = temp->next;
	}
	if (big && small)
		return (0);
	else if (big)
		return (1);
	else //small
		return (-1);
}

char	condition_sort3(t_elem *temp, int var)
{
	char	flag;

	flag = find_flag(temp, var); //1 - big, -1 - small, 0 - between

	if (flag == 1 && temp->var < var && temp->var < temp->next->var)
		return (0);
	else if (flag == -1 && temp->var > var && temp->var < temp->next->var)
		return (0);
	else if (temp->var > var && temp->next->var < var)
		return (0);
	else
		return (1);
}

int		find_q_rev(t_elem **a, int var)
{
	int		score;
	int		score_rev;
	t_elem	*temp;

	score = 0;
	score_rev = 0;
	temp = *a;
	while (condition_sort3(temp, var))
	{
		score++;
		temp = temp->prev;
	}
	temp = *a;
	while (condition_sort3(temp, var))
	{
		score_rev--;
		temp = temp->next;
	}
	if (score > score_rev * -1)
		return score_rev;
	else
		return score;
}
