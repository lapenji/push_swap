/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapenji <lapenji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:33:24 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/08 18:12:08 by lapenji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lis_finder(t_lista *lista, t_prg *prg)
{
	t_lista	*tmp;
	int		tmpnb;
	int		count;

	prg->max_count = 0;
	tmp = lista;
	count = 1;
	tmpnb = tmp->nb;
	while (tmp)
	{
		if (tmpnb < tmp->nb)
		{
			tmpnb = tmp->nb;
			count++;
		}
		tmp = tmp->next;
	}
	if (count > prg->max_count)
	{
		prg->max_count = count;
		prg->best_lis = lista->nb;
	}
}

int	ft_doing_ra_counter(t_lista *lista, int nb)
{
	int		i;

	i = 0;
	while (lista->nb != nb && lista->next)
	{
		lista = lista->next;
		i++;
	}
	if (lista->nb == nb)
		return (i);
	else
		return (9999);
}

int	ft_doing_rra_counter(t_lista *lista, int nb)
{
	int		i;
	t_lista	*tmp;

	tmp = ft_list_last(lista);
	i = 0;
	while (lista->nb != nb && lista->prev)
	{
		lista = lista->prev;
		i++;
	}
	if (lista->nb == nb)
	{
		return (i);
	}
	else
	{
		i += ft_doing_rra_counter(tmp, nb) + 1;
		return (i);
	}
}
