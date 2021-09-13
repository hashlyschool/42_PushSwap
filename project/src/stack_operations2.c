#include "push_swap.h"

void	print_operation(t_elem **from, char print)
{
	if (*from)
	{
		if ((*from)->name == 'a')
		{
			(*from)->name = 'b';
			if (print)
				ft_putstr_fd("pb\n", 1);
		}
		else if ((*from)->name == 'b')
		{
			(*from)->name = 'a';
			if (print)
				ft_putstr_fd("pa\n", 1);
		}
	}
}

void	push_2(t_elem **in, t_elem *temp)
{
	if (*in)
	{
		(*in)->next->prev = temp;
		temp->prev = *in;
		temp->next = (*in)->next;
		(*in)->next = temp;
		*in = temp;
	}
	else
	{
		*in = temp;
		temp->prev = *in;
		temp->next = *in;
	}
}

void	push(t_elem **from, t_elem **in, char print)
{
	t_elem	*temp;

	print_operation(from, print);
	if (*from == NULL)
		return ;
	temp = *from;
	if (temp->next == temp)
		*from = 0;
	else
	{
		(*from)->next->prev = temp->prev;
		(*from) = temp->prev;
		(*from)->next = temp->next;
		(*from)->prev = temp->prev->prev;
	}
	push_2(in, temp);
}

void	rev_rotate(t_elem **lst, char print)
{
	if (*lst && len_stack(*lst) > 1)
	{
		*lst = (*lst)->next;
		if ((*lst)->name == 'a' && print)
			ft_putstr_fd("rra\n", 1);
		else if (print)
			ft_putstr_fd("rrb\n", 1);
	}
	return ;
}

void	rev_rr(t_elem **a, t_elem **b, char print)
{
	if (*a && len_stack(*a) > 1)
		*a = (*a)->next;
	if (*b && len_stack(*b) > 1)
		*b = (*b)->next;
	if ((*a || *b) && print)
		ft_putstr_fd("rrr\n", 1);
	return ;
}
