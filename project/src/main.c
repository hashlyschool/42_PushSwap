#include "push_swap.h"

void	print_stack(t_elem *lst)
{
	t_elem	*temp;


	ft_putstr_fd("Stack:\n", 1);
	if (!lst)
		return ;
	temp = lst;
	ft_putnbr_fd(temp->next->var, 1);
	ft_putstr_fd(&temp->next->name, 1);
	ft_putstr_fd("\t-\t", 1);
	ft_putnbr_fd(temp->var, 1);
	ft_putstr_fd(&temp->name, 1);
	ft_putstr_fd("\t-\t", 1);
	ft_putnbr_fd(temp->prev->var, 1);
	ft_putstr_fd(&temp->prev->name, 1);
	ft_putstr_fd("\n", 1);
	while(temp != lst->next)
	{
		temp = temp->prev;
		ft_putnbr_fd(temp->next->var, 1);
		ft_putstr_fd(&temp->next->name, 1);
		ft_putstr_fd("\t-\t", 1);
		ft_putnbr_fd(temp->var, 1);
		ft_putstr_fd(&temp->name, 1);
		ft_putstr_fd("\t-\t", 1);
		ft_putnbr_fd(temp->prev->var, 1);
		ft_putstr_fd(&temp->prev->name, 1);
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("\n", 1);
}

int	main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;

	check_errors(argc, argv);
	create_lists(&a, &b, argc, argv);
	check_doubles(a);
	stack_is_sort(a);
	//test
	{
	push(&a, &b);
	push(&a, &b);
	push(&a, &b);
	push(&b, &a);
	print_stack(a);
	print_stack(b);
	rotate(&a);
	rotate(&b);
	rr(&a, &b);
	print_stack(a);
	print_stack(b);
	rev_rotate(&a);
	rev_rotate(&b);
	rev_rr(&a, &b);
	print_stack(a);
	print_stack(b);
	ft_putnbr_fd(len_stack(a), 1);
	ft_putnbr_fd(len_stack(b), 1);
	}
//find max sort substack and push mid, >mid, <mid in stack b
	//predsort(a, b);
	//sort(a,b);
}
