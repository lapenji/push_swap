/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:33:31 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/06 16:49:11 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_for_doubles(t_lista *list, int nb)
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

void	ft_populate_list(t_lista **lst, int argc, char **argv)
{
	int	i;
	int	tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (ft_check_for_doubles(*lst, tmp) == 1)
		{
			write(2, "Error\n", 7);
			exit(-1);
		}
		ft_add_element(lst, tmp);
		i++;
	}
}

int	ft_checkinput_nbrs(int argc, char **argv)
{
	int	i;
	int	b;

	i = 0;
	b = 1;
	while (b < argc)
	{
		if (argv[b][i] == '-' && ft_is_number(argv[b][i + 1]) == 1)
			i++;
		while (argv[b][i])
		{
			if (ft_is_number(argv[b][i]) == 0)
				return (1);
			i++;
		}
		i = 0;
		b++;
	}
	return (0);
}
