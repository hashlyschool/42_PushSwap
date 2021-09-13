#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 1
//for exit
# include <stdlib.h>
//for MaxInt, MinInt
# include <limits.h>
# include "../libft/includes/libft.h"
# include <unistd.h>

typedef struct s_elem
{
	int				var;
	int				score_a;
	int				score_b;
	char			name;
	int				middle;
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
void	ft_error_malloc_not_exit(t_elem *lst, char *str);
void	stack_is_sort(t_elem *a);
//Working with a list
size_t	len_stack(t_elem *lst);
void	swap(t_elem **lst, char print);
void	ss(t_elem **a, t_elem **b, char print);
void	push(t_elem **from, t_elem **in, char print);
void	rotate(t_elem **lst, char print);
void	rr(t_elem **a, t_elem **b, char print);
void	rev_rotate(t_elem **lst, char print);
void	rev_rr(t_elem **a, t_elem **b, char print);
//predsort
void	find_mid(t_elem **a);
void	predsort(t_elem **a, t_elem **b);
char	define_operation(t_elem *a, t_elem *b, t_elem *start, t_elem *end);
void	sort_array(int *mas, int size);
void	mini_predsort(t_elem **a, t_elem **b);
//sort
void	sort_stacks(t_elem **a, t_elem **b);
void	find_scores(t_elem **a, t_elem **b);
void	operation(t_elem **a, t_elem **b);
int		find_q_rev(t_elem **a, int var);
void	zero_scores(t_elem **b);
void	finish_sort(t_elem **a);
//cheker
int		ft_sheck_rtn(char *surplus);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char *surplus, char *buf);
char	*get_next_line(int fd);
#endif
