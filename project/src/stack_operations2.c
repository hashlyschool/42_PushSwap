#include "push_swap.h"

void	print_operation(t_elem **from, t_elem **in)
{
	if (*from)
	{
		if ((*from)->name == 'a')
		{
			(*from)->name = 'b';
			ft_putstr_fd("pb\n", 1);
		}
		else if ((*from)->name == 'b')
		{
			(*from)->name = 'a';
			ft_putstr_fd("pa\n", 1);
		}
	}
	else if (*in)
	{
		if ((*in)->name == 'a')
		{
			if (*from)
				(*from)->name = 'b';
			ft_putstr_fd("pa\n", 1);
		}
		else if ((*in)->name == 'b')
		{
			if (*from)
				(*from)->name = 'a';
			ft_putstr_fd("pb\n", 1);
		}
	}
}

void	push(t_elem **from, t_elem **in)
{
	t_elem	*temp;

	print_operation(from, in);
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
	#ifdef PRINT_INFO
		ft_putstr_fd("size stack = ", 1);
		ft_putnbr_fd(len_stack(*from), 1);
		ft_putstr_fd("\n", 1);
	#endif
}

void	rev_rotate(t_elem **lst)
{
	if (*lst && len_stack(*lst) > 1)
	{
		*lst = (*lst)->next;
		if ((*lst)->name == 'a')
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("rrb\n", 1);
	}
	return ;
}

void	rev_rr(t_elem **a, t_elem **b)
{
	if (*a && len_stack(*a) > 1)
		*a = (*a)->next;
	if (*b && len_stack(*b) > 1)
		*b = (*b)->next;
	if (*a || *b)
		ft_putstr_fd("rrr\n", 1);
	return ;
}
