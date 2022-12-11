/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:41:22 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/11 11:31:57 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static void	ft_populate_list(t_lista **lst, int argc, char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			write(2, "Error\nargument outside int range\n", 34);
			exit(-1);
		}
		if (ft_check_for_doubles(*lst, tmp) == 1)
		{
			write(2, "Error\ndouble number\n", 21);
			exit(-1);
		}
		ft_add_element(lst, tmp);
		i++;
	}
}

static void	ft_choose_move_r(t_lista **a_stack, t_lista **b_stack, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0 && *a_stack != NULL)
		ft_do_ra_rb(a_stack);
	else if (ft_strncmp(line, "rb\n", 3) == 0 && *b_stack != NULL)
		ft_do_ra_rb(b_stack);
	else if (ft_strncmp(line, "rra\n", 4) == 0 && *a_stack != NULL)
		ft_do_rra_rrb(a_stack);
	else if (ft_strncmp(line, "rrb\n", 4) == 0 && *b_stack != NULL)
		ft_do_rra_rrb(b_stack);
	else if (ft_strncmp(line, "rrr\n", 4) == 0 && *b_stack != NULL
		&& *a_stack != NULL)
		ft_do_rrr(a_stack, b_stack);
	else if (ft_strncmp(line, "rr\n", 3) == 0 && *b_stack != NULL
		&& *a_stack != NULL)
		ft_do_rr(a_stack, b_stack);
	else
	{
		free(line);
		if (a_stack != NULL)
			ft_free_list(*a_stack);
		if (*b_stack != NULL)
			ft_free_list(*b_stack);
		write(2, "Error:\nmove does not exist or impossible\n", 42);
		exit(-1);
	}
}

static void	ft_execute_move(t_lista **a_stack, t_lista **b_stack, char *line)
{
	if (line == NULL)
		return ;
	else if (ft_strncmp(line, "sa\n", 3) == 0 && *a_stack != NULL)
		ft_do_sa_sb(*a_stack);
	else if (ft_strncmp(line, "sb\n", 3) == 0 && *b_stack != NULL)
		ft_do_sa_sb(*b_stack);
	else if (ft_strncmp(line, "ss\n", 3) == 0 && *b_stack != NULL
		&& *a_stack != NULL)
		ft_do_ss(a_stack, b_stack);
	else if (ft_strncmp(line, "r", 1) == 0)
		ft_choose_move_r(a_stack, b_stack, line);
	else if (ft_strncmp(line, "p", 1) == 0)
		ft_choose_move_p(a_stack, b_stack, line);
	else
	{
		free(line);
		if (*a_stack != NULL)
			ft_free_list(*a_stack);
		if (*b_stack != NULL)
			ft_free_list(*b_stack);
		write(2, "Error:\nmove does not exist or impossible\n", 42);
		exit(-1);
	}
	free(line);
}

static void	ft_populate_and_move(int argc, char **argv)
{
	char	*line;
	t_lista	*a_stack;
	t_lista	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	ft_populate_list(&a_stack, argc, argv);
	if (ft_is_list_ordered(a_stack) == 0)
	{
		line = get_next_line(0);
		ft_execute_move(&a_stack, &b_stack, line);
		while (line != NULL)
		{
			line = get_next_line(0);
			ft_execute_move(&a_stack, &b_stack, line);
		}
	}
	if (ft_is_list_ordered(a_stack) == 0 || b_stack != NULL)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_free_list(a_stack);
}

int	main(int argc, char **argv)
{
	long	tmp;

	if (argc > 1)
	{
		if (ft_checkinput_nbrs(argc, argv) == 1)
		{
			write(2, "Error\none argument is not a number\n", 36);
			exit(-1);
		}
		tmp = ft_atoi(argv[1]);
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			write(2, "Error\nargument outside int range\n", 34);
			exit(-1);
		}
		if (argc >= 3)
			ft_populate_and_move(argc, argv);
	}
}
