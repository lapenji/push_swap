/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapenji <lapenji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:06 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/08 17:10:46 by lapenji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_in_b_five_n_solve(t_lista **a, t_lista **b)
{
	int	tmp;

	if (ft_is_list_ordered(*a) == 0)
	{
		while (ft_list_length(*a) > 3)
		{
			tmp = ft_find_min(*a);
			while ((*a)->nb != tmp)
			{
				if (ft_doing_ra_counter(*a, tmp)
					< ft_doing_rra_counter(*a, tmp))
				{
					while ((*a)->nb != tmp)
						ra_rb(a, 'a');
				}
				else
				{
					while ((*a)->nb != tmp)
						rra_rrb(a, 'a');
				}
			}
			pa_pb(a, b, 'b');
		}
		ft_three_solver(a);
	}
}

void	ft_pusha_in_b(t_lista **a, t_lista **b, t_prg *prg)
{
	int	tmpmin;

	tmpmin = prg->best_lis;
	while (ft_list_length(*a) > prg->max_count)
	{
		if (tmpmin <= (*a)->nb)
		{
			tmpmin = (*a)->nb;
			ra_rb(a, 'a');
		}
		else
			pa_pb(a, b, 'b');
	}
}

void	ft_order_lis(t_lista **lista, int min)
{
	if (ft_doing_ra_counter(*lista, min) < ft_doing_rra_counter(*lista, min))
	{
		while ((*lista)->nb != min)
			ra_rb(lista, 'a');
	}
	else
	{
		while ((*lista)->nb != min)
			rra_rrb(lista, 'a');
	}
}

void	ft_three_solver(t_lista **a)
{
	if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb
		&& (*a)->nb < (*a)->next->next->nb)
		sa_sb(*a, 'a');
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb
		&& (*a)->nb > (*a)->next->next->nb)
	{
		sa_sb(*a, 'a');
		rra_rrb(a, 'a');
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb
		&& (*a)->nb > (*a)->next->next->nb)
		ra_rb(a, 'a');
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb
		&& (*a)->nb < (*a)->next->next->nb)
	{
		sa_sb(*a, 'a');
		ra_rb(a, 'a');
	}
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb
		&& (*a)->nb > (*a)->next->next->nb)
		rra_rrb(a, 'a');
}

void	sa_sb(t_lista *lista, char c)
{
	int	swap;

	swap = lista->nb;
	lista->nb = lista->next->nb;
	lista->next->nb = swap;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}
