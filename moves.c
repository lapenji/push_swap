/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:30 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/07 19:08:56 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_lista **lista, char c)
{
	int		tmp;
	t_lista	*temphead;

	temphead = (*lista)->next;
	tmp = (*lista)->nb;
	ft_add_element(lista, tmp);
	ft_remove_first(lista);
	*lista = temphead;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rra_rrb(t_lista	**lista, char c)
{
	int	tmp;

	if (c == 'b' && ft_list_length(*lista) == 1)
		return ;
	tmp = ft_list_last(*lista)->nb;
	ft_add_element_to_start(lista, tmp);
	ft_remove_last(lista);
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	pa_pb(t_lista **a, t_lista **b, char c)
{
	int	tmp;

	tmp = (*a)->nb;
	ft_add_element_to_start(b, tmp);
	ft_remove_first(a);
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	rab(t_lista **a, t_lista **b)
{
	ra_rb(a, 0);
	ra_rb(b, 0);
	write(1, "rr\n", 3);
}

void	rrab(t_lista **a, t_lista **b)
{
	rra_rrb(a, 0);
	rra_rrb(b, 0);
	write(1, "rrr\n", 4);
}
