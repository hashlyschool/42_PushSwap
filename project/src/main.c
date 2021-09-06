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
	ft_putnbr_fd(temp->next->middle, 1);
	ft_putstr_fd("\t-\t", 1);
	ft_putnbr_fd(temp->var, 1);
	ft_putstr_fd(&temp->name, 1);
	ft_putnbr_fd(temp->middle, 1);
	ft_putstr_fd("\t-\t", 1);
	ft_putnbr_fd(temp->prev->var, 1);
	ft_putstr_fd(&temp->prev->name, 1);
	ft_putnbr_fd(temp->prev->middle, 1);
	ft_putstr_fd("\n", 1);
	while(temp != lst->next)
	{
		temp = temp->prev;
		ft_putnbr_fd(temp->next->var, 1);
		ft_putstr_fd(&temp->next->name, 1);
		ft_putnbr_fd(temp->next->middle, 1);
		ft_putstr_fd("\t-\t", 1);
		ft_putnbr_fd(temp->var, 1);
		ft_putstr_fd(&temp->name, 1);
		ft_putnbr_fd(temp->middle, 1);
		ft_putstr_fd("\t-\t", 1);
		ft_putnbr_fd(temp->prev->var, 1);
		ft_putstr_fd(&temp->prev->name, 1);
		ft_putnbr_fd(temp->prev->middle, 1);
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
//find max sort substack and push mid, >mid, <mid in stack b
	predsort(&a, &b); //вроде готово, надо тестить, но на первый взгляд - все работает
	sort_stacks(&a,&b); //не готово

	/*//test print
	{
	ft_putstr_fd("\n", 1);
	print_stack(b);
	ft_putstr_fd("len stack b = ", 1);
	ft_putnbr_fd(len_stack(b), 1);
	ft_putstr_fd("\n", 1);
	}
	{
	ft_putstr_fd("\n", 1);
	print_stack(a);
	ft_putstr_fd("len stack a = ", 1);
	ft_putnbr_fd(len_stack(a), 1);
	ft_putstr_fd("\n", 1);
	}
	//end test print*/
}
