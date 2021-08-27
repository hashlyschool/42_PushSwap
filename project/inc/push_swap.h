#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//for exit
# include <stdlib.h>
//for MaxInt, MinInt
# include <limits.h>
# include "../libft/includes/libft.h"

//for printf
#include <stdio.h>

typedef struct s_elem
{
	int				var;
	int				elem_score;
	char			name;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;
//errors
void	check_errors(int argc, char **argv);
void	check_doubles(t_elem *lst);
//fill stack a from argv
void	create_lists(t_elem **a, t_elem **b, int argc, char **argv);
//exit_func
void	ft_error_arg(char *str);
void	ft_error_malloc(t_elem *lst, char *str);
void	stack_is_sort(t_elem *a);
//Working with a list
size_t	len_stack(t_elem *lst);
void	swap(t_elem **lst);
void	ss(t_elem **a, t_elem **b);
void	push(t_elem **from, t_elem **in);
void	rotate(t_elem **lst);
void	rr(t_elem **a, t_elem **b);
void	rev_rotate(t_elem **lst);
void	rev_rr(t_elem **a, t_elem **b);
//predsort
void	predsort(t_elem **a, t_elem **b);

#endif