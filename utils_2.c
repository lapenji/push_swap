#include "push_swap.h"

void	ft_order_lis(t_lista *lista, t_prg *prg, char c)
{
	int tmp;

	if (c == 'a')
	{
		tmp = prg->best_lis;
	}
	else
	{
		tmp = prg->min_nb_b;
	}
	if (ft_doing_ra_lis(lista, tmp) < ft_doing_rra_lis(lista, tmp))
	{
			while (lista->nb != tmp)
			ra_rb(lista, c);
	}
	else
	{
		while (lista->nb != tmp)
			rra_rrb(lista, c);
	}
}

void	ft_pusha_in_b(t_lista **a, t_lista **b, t_prg *prg)
{
	int	tmpmax;

	tmpmax = prg->best_lis;
	while (ft_list_length(*a) > prg->max_count)
	{
		if ((*a)->nb < tmpmax)
			pa_pb(a, b, 'b');
		else
		{
			tmpmax = (*a)->nb;
			ra_rb(*a, 'a');
		}
	}
}
