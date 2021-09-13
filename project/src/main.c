#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;

	check_errors(argc, argv);
	create_lists(&a, &b, argc, argv);
	check_doubles(a);
	stack_is_sort(a);
	find_mid(&a);
	if (argc > 6)
		predsort(&a, &b);
	else
		mini_predsort(&a, &b);
	sort_stacks(&a, &b);
	stack_is_sort(a);
}
