/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:33:59 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/10 10:37:24 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

int	ft_find_min(t_lista *lista)
{
	int	tmpmin;

	tmpmin = lista->nb;
	while (lista)
	{
		if (lista->nb < tmpmin)
			tmpmin = lista->nb;
		lista = lista->next;
	}
	return (tmpmin);
}

int	ft_absolute(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int	ft_is_number(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
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
