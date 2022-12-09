/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:17 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/09 18:33:33 by ltombell         ###   ########.fr       */
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
