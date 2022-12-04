#include "push_swap.h"

void	ft_push_in_b_five_n_solve(t_lista **a, t_lista **b)
{
	int	tmp;

	if (ft_is_list_ordered(*a) == 0)
	{
		while (ft_list_length(*a) > 3)
		{
			tmp = ft_find_min(*a);
			while ((*a)->nb != tmp)
			{
				if (ft_doing_ra_lis(*a, tmp) < ft_doing_rra_lis(*a, tmp))
				{
					while ((*a)->nb != tmp)
						ra_rb(*a, 'a');
				}
				else
				{
					while ((*a)->nb != tmp)
						rra_rrb(*a, 'a');
				}
			}
			pa_pb(a, b, 'b');
		}
		ft_three_solver(*a);
	}
}

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

void	ft_three_solver(t_lista *a)
{
	if (a->nb > a->next->nb && a->next->nb < a->next->next->nb
		&& a->nb < a->next->next->nb)
		sa_sb(a, 'a');
	else if (a->nb > a->next->nb && a->next->nb > a->next->next->nb
		&& a->nb > a->next->next->nb)
	{
		sa_sb(a, 'a');
		rra_rrb(a, 'a');
	}
	else if (a->nb > a->next->nb && a->next->nb < a->next->next->nb
		&& a->nb > a->next->next->nb)
		ra_rb(a, 'a');
	else if (a->nb < a->next->nb && a->next->nb > a->next->next->nb
		&& a->nb < a->next->next->nb)
	{
		sa_sb(a, 'a');
		ra_rb(a, 'a');
	}
	else if (a->nb < a->next->nb && a->next->nb > a->next->next->nb
		&& a->nb > a->next->next->nb)
		rra_rrb(a, 'a');
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
