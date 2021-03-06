/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:46:35 by hashly            #+#    #+#             */
/*   Updated: 2021/09/14 10:47:30 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_operation2(t_elem **a, t_elem **b, char **line,
	size_t len_str)
{
	if (!ft_strncmp(*line, "rra\n", len_str) && len_str == 4)
		rev_rotate(a, 0);
	else if (!ft_strncmp(*line, "rrb\n", len_str) && len_str == 4)
		rev_rotate(b, 0);
	else if (!ft_strncmp(*line, "rrr\n", len_str) && len_str == 4)
		rev_rr(a, b, 0);
	else
	{
		free(*line);
		get_next_line(0, 1);
		ft_error_malloc_not_exit(*a, "");
		ft_error_malloc(*b, "KO\n");
	}
}

void	checker_operation(t_elem **a, t_elem **b, char **line)
{
	size_t	len_str;

	if (*line && ft_strlen(*line))
	{
		len_str = ft_strlen(*line);
		if (!ft_strncmp(*line, "sa\n", len_str) && len_str == 3)
			swap(a, 0);
		else if (!ft_strncmp(*line, "sb\n", len_str) && len_str == 3)
			swap(b, 0);
		else if (!ft_strncmp(*line, "ss\n", len_str) && len_str == 3)
			ss(a, b, 0);
		else if (!ft_strncmp(*line, "pa\n", len_str) && len_str == 3)
			push(b, a, 0);
		else if (!ft_strncmp(*line, "pb\n", len_str) && len_str == 3)
			push(a, b, 0);
		else if (!ft_strncmp(*line, "ra\n", len_str) && len_str == 3)
			rotate(a, 0);
		else if (!ft_strncmp(*line, "rb\n", len_str) && len_str == 3)
			rotate(b, 0);
		else if (!ft_strncmp(*line, "rr\n", len_str) && len_str == 3)
			rr(a, b, 0);
		else
			checker_operation2(a, b, line, len_str);
	}
}

void	stack_is_sort_shecker(t_elem *a, t_elem *b)
{
	t_elem	*temp1;
	t_elem	*temp2;
	char	sort;

	temp1 = a;
	sort = 0;
	if (b)
	{
		if (a)
			ft_error_malloc_not_exit(a, "");
		ft_error_malloc(b, "KO\n");
	}
	while (temp1 != a->next)
	{
		temp2 = temp1->prev;
		if (temp1->var > temp2->var)
		{
			ft_error_malloc_not_exit(a, "");
			ft_error_malloc(b, "KO\n");
		}
		temp1 = temp1->prev;
	}
	ft_error_malloc(a, "OK\n");
}

int	main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;
	char	*line;

	check_errors(argc, argv);
	create_lists(&a, &b, argc, argv);
	check_doubles(a);
	line = get_next_line(0, 0);
	while (line && ft_strlen(line))
	{
		checker_operation(&a, &b, &line);
		free(line);
		line = get_next_line(0, 0);
	}
	checker_operation(&a, &b, &line);
	free(line);
	stack_is_sort_shecker(a, b);
}
