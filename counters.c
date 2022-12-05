#include "push_swap.h"

static int	ft_find_value(t_prg *prg, int i)
{
	if (prg->mova[i] >= 0 && prg->movb[i] >= 0)
	{
		if (prg->mova[i] > prg->movb[i])
			return (prg->mova[i]);
		else
			return (prg->movb[i]);
	}
	else if (prg->mova[i] >= 0 && prg->movb[i] <= 0)
		return (prg->mova[i] + ft_absolute(prg->movb[i]));
	else if (prg->mova[i] <= 0 && prg->movb[i] >= 0)
		return (ft_absolute(prg->mova[i]) + prg->movb[i]);
	else
	{
		if (prg->mova[i] < prg->movb[i])
			return (ft_absolute(prg->mova[i]));
		else
			return (ft_absolute(prg->movb[i]));
	}
}

int	ft_find_best_move(t_lista **b, t_prg *prg)
{
	int	i;
	int	x;
	int	best;
	int	besti;
	int	tmp;

	besti = 0;
	i = 0;
	best = ft_find_value(prg, i);
	x = ft_list_length(*b);
	while (i < x)
	{
		tmp = ft_find_value(prg, i);
		if (tmp < best)
		{
			best = tmp;
			besti = i;
		}
		i++;
	}
	return (besti);
}

static int	ft_find_best_move_helper(t_lista **a, int target)
{
	t_lista	*tmpa;
	int		res;

	res = 0;
	tmpa = *a;
	while ((tmpa->nb > target || target > tmpa->next->nb) && tmpa)
	{
		res++;
		tmpa = tmpa->next;
	}
	res++;
	if (res >= (ft_list_length(*a) / 2))
		res = ((ft_list_length(*a) - res) * -1);
	return (res);
}

int	ft_find_best_move_ra(t_lista **a, int target, t_prg *prg)
{
	int	res;
	int	ra;
	int	rra;

	res = 0;
	prg->min_nb_a = ft_find_min(*a);
	if (target < (*a)->nb && target > ft_list_last(*a)->nb)
		return (0);
	else if (target < prg->min_nb_a)
	{
		rra = ft_doing_rra_lis(*a, prg->min_nb_a);
		ra = ft_doing_ra_lis(*a, prg->min_nb_a);
		if (ra <= rra)
			res = ra;
		else
			res = rra * -1;
	}
	else
		res = ft_find_best_move_helper(a, target);
	return (res);
}
