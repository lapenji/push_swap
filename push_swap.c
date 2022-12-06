/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:35 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/06 18:51:42 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_solve_two(t_lista *a_stack)
{
	if (a_stack->nb != ft_find_min(a_stack))
		ra_rb(&a_stack, 'a');
	ft_free_list(a_stack);
}

static void	ft_solve_less(int argc, char **argv)
{
	t_lista	*a_stack;
	t_lista	*b_stack;
	t_prg	prg;

	a_stack = NULL;
	b_stack = NULL;
	ft_populate_list(&a_stack, argc, argv);
	if (argc == 3)
		ft_solve_two(a_stack);
	else if (argc == 4)
	{
		ft_three_solver(&a_stack);
		ft_free_list(a_stack);
	}
	else
	{
		ft_push_in_b_five_n_solve(&a_stack, &b_stack);
		while (ft_list_length(b_stack) > 0)
			pa_pb(&b_stack, &a_stack, 'a');
		prg.min_nb_a = ft_find_min(a_stack);
		ft_order_lis(&a_stack, prg.min_nb_a);
		ft_free_list(a_stack);
	}
}

static void	ft_solve_more(int argc, char **argv)
{
	t_lista	*a_stack;
	t_lista	*b_stack;
	t_prg	prg;

	a_stack = NULL;
	b_stack = NULL;
	ft_populate_list(&a_stack, argc, argv);
	if (ft_is_list_ordered(a_stack) == 0)
	{
		ft_lis_finder(a_stack, &prg);
		ft_order_lis(&a_stack, prg.best_lis);
		ft_pusha_in_b(&a_stack, &b_stack, &prg);
		ft_pusha_in_a(&a_stack, &b_stack, &prg);
		prg.min_nb_a = ft_find_min(a_stack);
		ft_order_lis(&a_stack, prg.min_nb_a);
		ft_free_list(a_stack);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_checkinput_nbrs(argc, argv) == 1)
		{
			write(2, "Error\n", 7);
			exit(-1);
		}
		else if (argc <= 11 && argc > 2)
			ft_solve_less(argc, argv);
		else if (argc > 2)
			ft_solve_more(argc, argv);
	}
	else
		write(1, "\n", 1);
}
