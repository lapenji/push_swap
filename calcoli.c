#include "push_swap.h"

void	ft_lis_first(t_lista *lista, t_prg *prg)
{
	t_lista	*tmp;
	int	count;
	int	tmpnb;
	int	i;
	int	tmpnb2;

	i = 0;
	count = 1;
	prg->max_count = 0;

	while (i < ft_list_length(lista))
	{
		tmp = lista;
		tmpnb = tmp->nb;
		tmpnb2 = tmp->nb;
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
			prg->best_lis = tmpnb2;
		}
		count = 1;
		ra_rb(lista, 0);
		i++;
	}
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

int	ft_find_max(t_lista *lista)
{
	int	tmpmax;

	tmpmax = lista->nb;
	while (lista)
	{
		if (lista->nb > tmpmax)
			tmpmax = lista->nb;
		lista = lista->next;
	}
	return (tmpmax);
}
