/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:17 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/10 10:58:06 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_remove_first(t_lista **lista)
{
	t_lista	*tmp;

	tmp = *lista;
	if ((*lista)->next)
	{
		*lista = (*lista)->next;
		(*lista)->prev = NULL;
		free (tmp);
	}
	else
	{
		free(tmp);
		*lista = NULL;
	}
}

t_lista	*ft_list_last(t_lista *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_remove_last(t_lista **lista)
{
	t_lista	*tmp;
	t_lista	*tmp2;

	tmp = *lista;
	while ((*lista)->next)
		*lista = (*lista)->next;
	if ((*lista)->prev)
	{
		tmp2 = *lista;
		*lista = (*lista)->prev;
		(*lista)->next = NULL;
		free (tmp2);
	}
	else
		(*lista) = NULL;
	*lista = tmp;
}

void	ft_free_list(t_lista *lst)
{
	t_lista	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int	ft_is_list_ordered(t_lista	*lst)
{
	t_lista	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
