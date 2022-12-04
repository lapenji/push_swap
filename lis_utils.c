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
	ra_rb(lista, 0);
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
	int	b;

	i = 0;
	while (lista->nb != nb)
	{
		ra_rb(lista, 0);
		i++;
	}
	b = i;
	while (i > 0)
	{
		rra_rrb(lista, 0);
		i--;
	}
	return (b);
}

int	ft_doing_rra_lis(t_lista *lista, int nb)
{
	int	i;
	int	b;
	t_lista	*tmp;

	i = 0;
	tmp = lista;
	while (tmp->nb != nb)
	{
		rra_rrb(lista, 0);
		i++;
	}
	b = i;
	while (i > 0)
	{
		ra_rb(lista, 0);
		i--;
	}
	return (b);
}
