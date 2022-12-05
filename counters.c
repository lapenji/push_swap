#include "push_swap.h"

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
