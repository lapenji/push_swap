#include "push_swap.h"

static void	ft_lis_finder_helper(t_lista *lista, t_prg *prg)
{
	t_lista	*tmp;
	int		tmpnb;
	int		count;

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

void	ft_lis_finder(t_lista *lista, t_prg *prg)
{
	int		i;

	i = 0;
	prg->max_count = 0;
	while (i < ft_list_length(lista))
	{
		ft_lis_finder_helper(lista, prg);
		i++;
	}
}

int	ft_doing_ra_lis(t_lista *lista, int nb)
{
	int	i;

	i = 0;
	while (lista->nb != nb && lista->next)
	{
		lista = lista->next;
		i++;
	}
	if (lista->nb == nb)
		return (i);
	else
		return (99999);
}

int	ft_doing_rra_lis(t_lista *lista, int nb)
{
	int	i;

	i = 0;
	while (lista->nb != nb && lista->prev)
	{
		lista = lista->prev;
		i++;
	}
	if (lista->nb == nb)
		return (i);
	else
		return (99999);
}
