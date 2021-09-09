#include "push_swap.h"

size_t	len_stack(t_elem *lst)
{
	t_elem	*last;
	size_t	len;

	if (lst)
		len = 1;
	else
		return (0);
	last = lst->next;
	while (lst != last)
	{
		lst = lst->prev;
		len++;
	}
	return (len);
}

void	swap(t_elem **lst)
{
	t_elem	*lst_prev;
	t_elem	*next_1;
	t_elem	*prev_2;
	size_t	len;

	len = len_stack(*lst);
	if (len > 2)
	{
		lst_prev = (*lst)->prev;
		next_1 = (*lst)->next;
		prev_2 = lst_prev->prev;
		(*lst)->next = lst_prev;
		(*lst)->prev = prev_2;
		lst_prev->next = next_1;
		lst_prev->prev = (*lst);
		next_1->prev = lst_prev;
		prev_2->next = (*lst);
		(*lst) = lst_prev;
	}
	else if (len == 2)
		*lst = (*lst)->prev;
	if ((*lst) && (*lst)->name == 'a')
		ft_putstr_fd("sa\n", 1);
	else if ((*lst) && (*lst)->name == ' ')
		return ;
	else
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_elem **a, t_elem **b)
{
	if (len_stack(*a) > 1)
	{
		(*a)->prev->name = ' ';
		swap(a);
		(*a)->name = 'a';
	}
	if (len_stack(*b) > 1)
	{
		(*b)->prev->name = ' ';
		swap(b);
		(*b)->name = 'b';
	}
	ft_putstr_fd("ss\n", 1);
	return ;
}

void	rotate(t_elem **lst)
{
	if (*lst && len_stack(*lst) > 1)
	{
		*lst = (*lst)->prev;
		if ((*lst)->name == 'a')
			ft_putstr_fd("ra\n", 1);
		else
			ft_putstr_fd("rb\n", 1);
	}
	return ;
}

void	rr(t_elem **a, t_elem **b)
{
	if (*a && len_stack(*a) > 1)
		*a = (*a)->prev;
	if (*b && len_stack(*b) > 1)
		*b = (*b)->prev;
	if (*a || *b)
		ft_putstr_fd("rr\n", 1);
	return ;
}
