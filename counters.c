#include "push_swap.h"

static int	ft_find_best_minimum_ra(t_lista *a, t_prg *prg)
{
	int	res;

	res = 0;
	while (a->nb != prg->min_nb_a && a)
	{
		res++;
		a = a->next;
	}
	return (res);
}

static int	ft_find_best_minimum_rra(t_lista *a, t_prg *prg)
{
	int	res;

	res = 0;
	a = ft_list_last(a);
	while (a->nb != prg->min_nb_a && a)
	{
		res++;
		a = a->prev;
	}
	return (res + 1);
}

int	ft_find_best_move_ra(t_lista *a, int target, t_prg *prg)
{
	int	res;
	int	i;

	res = 0;
	prg->min_nb_a = ft_find_min(a);
	if (target < prg->min_nb_a)
		res = ft_find_best_minimum_ra(a, prg);
	else
	{
		while (!(target < a->nb && target > ft_list_last(a)->nb))
		{
			ra_rb(a, 0);
			res++;
		}
		i = res;
		while (i > 0)
		{
			rra_rrb(a, 0);
			i--;
		}
	}
	return (res);
}

int	ft_find_best_move_rra(t_lista *a, int target, t_prg *prg)
{
	int	res;
	int	i;

	res = 0;
	prg->min_nb_a = ft_find_min(a);
	if (target < prg->min_nb_a)
		res = ft_find_best_minimum_rra(a, prg);
	else
	{
		while (!(target < a->nb && target > ft_list_last(a)->nb))
		{
			rra_rrb(a, 0);
			res++;
		}
		i = res;
		while (i > 0)
		{
			ra_rb(a, 0);
			i--;
		}
	}
	return (res * -1);
}
