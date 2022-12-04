#include "push_swap.h"

void	ft_pusha_in_b(t_lista **a, t_lista **b, t_prg *prg)
{
	int	tmpmax;

	tmpmax = prg->best_lis;
	while (ft_list_length(*a) > prg->max_count)
	{
		if (tmpmax <= (*a)->nb)
		{
			tmpmax = (*a)->nb;
			ra_rb(*a, 'a');
		}
		else
			pa_pb(a, b, 'b');
	}
}

void	ft_order_lis(t_lista *lista, int min)
{
	if (ft_doing_ra_lis(lista, min) < ft_doing_rra_lis(lista, min))
	{
		while (lista->nb != min)
			ra_rb(lista, 'a');
	}
	else
	{
		while (lista->nb != min)
			rra_rrb(lista, 'a');
	}
}

void	sa_sb(t_lista *lista, char c)
{
	int	swap;

	swap = lista->nb;
	lista->nb = lista->next->nb;
	lista->next->nb = swap;
	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
}
