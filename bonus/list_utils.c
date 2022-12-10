/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:23 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/10 11:18:15 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_lista	*create_elem(int n)
{
	t_lista	*elem;

	elem = (t_lista *)malloc(sizeof(t_lista));
	elem->nb = n;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	ft_add_element(t_lista **lista, int n)
{
	t_lista	*new;
	t_lista	*tmp;

	if (!*lista)
		*lista = create_elem(n);
	else
	{
		tmp = *lista;
		while (tmp->next)
			tmp = tmp->next;
		new = create_elem(n);
		tmp->next = new;
		new->prev = tmp;
	}
}

int	ft_list_length(t_lista *lista)
{
	t_lista	*tmp;
	int		i;

	i = 0;
	tmp = lista;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_add_element_to_start(t_lista **lista, int nb)
{
	t_lista	*new;

	new = create_elem(nb);
	if (!*lista)
		*lista = new;
	else
	{
		new->next = (*lista);
		(*lista)->prev = new;
		*lista = new;
	}
}

int	ft_check_for_doubles(t_lista *list, int nb)
{
	t_lista	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
