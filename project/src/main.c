#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;

	a = 0;
	b = 0;
	check_errors(argc, argv);
	//ft_putstr_fd("good argv\n", 1);
	create_lists(&a, argc, argv);
	//print stack a
	{
	int i;
	t_elem	*temp;

	i = a->var;
	temp = a;
	ft_putnbr_fd(i, 1);
	ft_putstr_fd(" ", 1);
	while(temp != a->next)
	{
		temp = temp->prev;
		ft_putnbr_fd(temp->var, 1);
		ft_putstr_fd(" ", 1);
	}
	ft_putstr_fd("\n", 1);
	}
	//end print stack a
	check_doubles(a);
	stack_is_sort(a);
 //find max sort substack and push mid, >mid, <mid in stack b
	//predsort(a, b);
	//sort(a,b);
}
