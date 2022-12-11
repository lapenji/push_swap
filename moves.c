/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:30 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/11 11:32:59 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_lista **lista, char c)
{
	t_lista	*tmp;
	t_lista	*putback;

	if ((*lista)->next != NULL)
	{
		putback = *lista;
		tmp = *lista;
		while (tmp->next)
			tmp = tmp->next;
		*lista = (*lista)->next;
		tmp->next = putback;
		putback->next = NULL;
		putback->prev = tmp;
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1, "rb\n", 3);
	}
}

void	rra_rrb(t_lista **head, char c)
{
	t_lista	*tmp;
	t_lista	*prev;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	else
	{
		tmp = *head;
		prev = *head;
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *head;
		tmp->prev = NULL;
		tmp->next->prev = tmp;
		*head = tmp;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
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
