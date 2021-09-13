#include "push_swap.h"

void	ft_error_arg(char *str)
{
	ft_putstr_fd(str, 1);
	exit (0);
}

void	ft_error_malloc_not_exit(t_elem *lst, char *str)
{
	t_elem	*prev, *next;

	ft_putstr_fd(str, 1);
	while (lst)
	{
		if (lst == lst->next)
		{
			free(lst);
			return ;
		}
		prev = lst->prev;
		next = lst->next;
		prev->next = lst->next;
		next->prev = lst->prev;
		free(lst);
		lst = next;
	}
}

void	ft_error_malloc(t_elem *lst, char *str)
{
	t_elem	*prev, *next;

	ft_putstr_fd(str, 1);
	while (lst)
	{
		if (lst == lst->next)
		{
			free(lst);
			exit (0);
		}
		prev = lst->prev;
		next = lst->next;
		prev->next = lst->next;
		next->prev = lst->prev;
		free(lst);
		lst = next;
	}
	exit (0);
}

void	stack_is_sort(t_elem *a)
{
	t_elem	*temp1, *temp2;
	char	sort;

	temp1 = a;
	sort = 0;
	while(temp1 != a->next)
	{
		temp2 = temp1->prev;
		if (temp1->var > temp2->var)
			return ; //stack is not sort\n
		temp1 = temp1->prev;
	}
	ft_error_malloc(a, ""); //"stack is sort\n"
}
