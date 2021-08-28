#include "push_swap.h"

/*
возвращает 1, если елемент a , входит в последовательность
возвращает 0, если элемент не входит в последовательность
*/
char	check_elem_in_substack(t_elem *a, t_elem *start, t_elem *end)
{
	a = 0;
	start = 0;
	end = 0;
	return (0);
}

/*
Функция должна анализировать стеки 'a' and 'b' и определять код необходимой операции по правилу:
return:
	1 - pa
	2 - ra
	3 - rb
	4 - rr
	5 - rra
	6 - rrb
	7 - rrr
*/
char	define_operation(t_elem *a, t_elem *b, t_elem *start, t_elem *end)
{
	char	elem_in_substack;

	elem_in_substack = check_elem_in_substack(a, start, end);
	a = 0;
	b = 0;
	start = 0;
	end = 0;
	return (0);
}// не готово
