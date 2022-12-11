/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 10:59:31 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/11 11:15:12 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_do_rrr(t_lista **a, t_lista **b)
{
	ft_do_rra_rrb(a);
	ft_do_rra_rrb(b);
}

void	ft_do_ss(t_lista **a, t_lista **b)
{
	ft_do_sa_sb(*a);
	ft_do_sa_sb(*b);
}

void	ft_choose_move_p(t_lista **a_stack, t_lista **b_stack, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0 && *b_stack != NULL)
		ft_do_pa_pb(b_stack, a_stack);
	else if (ft_strncmp(line, "pb\n", 3) == 0 && *a_stack != NULL)
		ft_do_pa_pb(a_stack, b_stack);
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
