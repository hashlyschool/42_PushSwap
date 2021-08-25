#include "push_swap.h"

void	new_elem(t_elem **lst, int var)
{
	*lst = (t_elem*)malloc(sizeof(t_elem));
	if (*lst == NULL)
		ft_error_malloc(*lst, "Error malloc\n");
	(*lst)->var = var;
	(*lst)->next = *lst;
	(*lst)->prev = *lst;
}

void push_back(t_elem **lst, int var)
{
	t_elem	*temp, *last_lst;

	temp = (t_elem*)malloc(sizeof(t_elem));
	if (*lst == NULL)
		ft_error_malloc(*lst, "Error malloc\n");
	temp->var = var;
	last_lst = (*lst)->next;
	(*lst)->next = temp;
	last_lst->prev = temp;
	temp->next = last_lst;
	temp->prev = *lst;
}

void add_elem(t_elem **lst, int var)
{
	if (*lst == NULL)
		new_elem(lst, var);
	else
		push_back(lst, var);
}

void	create_lists(t_elem **a, int argc, char **argv)
{
	int	i;

	i = 1;
	while(i < argc)
	{
		add_elem(a, ft_atoi(argv[i]));
		i++;
	}
}
