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
	int		var;
	int		elem_score;
	struct s_elem *next;
	struct s_elem *prev;
}				t_elem;
//errors
void	check_errors(int argc, char **argv);
void	check_doubles(t_elem *lst);
//fill stack a from argv
void	create_lists(t_elem **a, int argc, char **argv);
//exit_func
void	ft_error_arg(char *str);
void	ft_error_malloc(t_elem *lst, char *str);
void	stack_is_sort(t_elem *a);
//Working with a list
//pa
//pb
//...


#endif
