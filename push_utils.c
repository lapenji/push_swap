#include "push_swap.h"

static void	ft_pusha_in_a_normal(t_lista *b, t_lista *a)
{
	if (ft_doing_ra_target(a, b->nb) < ft_doing_rra_target(a, b->nb))
	{
		while (!(b->nb < a->nb && b->nb > ft_list_last(a)->nb))
			ra_rb(a, 'a');
		pa_pb(&b, &a, 'a');
		rra_rrb(a, 'a');
	}
	else
	{
		while (!(b->nb < a->nb && b->nb > ft_list_last(a)->nb))
			rra_rrb(a, 'a');
		pa_pb(&b, &a, 'a');
		ra_rb(a, 'a');
	}
}

static void	ft_pusha_in_a_min(t_lista *b, t_lista *a, t_prg *prg)
{
	if (ft_doing_ra_case_2(a, prg->min_nb_a) < ft_doing_rra_case_2(a, prg->min_nb_a))
	{
		while (a->nb != prg->min_nb_a)
			ra_rb(a, 'a');
	}
	else
	{
		while (a->nb != prg->min_nb_a)
			rra_rrb(a, 'a');
	}
	pa_pb(&b, &a , 'a');
	prg->min_nb_a = ft_find_min(a);
}

static void	ft_pusha_in_a_max(t_lista *b, t_lista *a, t_prg *prg)
{
	if (ft_doing_ra_case_2(a, prg->max_nb_a) < ft_doing_rra_case_2(a, prg->max_nb_a))
	{
		while (a->nb != prg->max_nb_a)
			ra_rb(a, 'a');
	}
	else
	{
		while (a->nb != prg->max_nb_a)
			rra_rrb(a, 'a');
	}
	pa_pb(&b, &a, 'a');
	prg->max_nb_a = ft_find_max(a);
}

void	ft_pusha_in_a(t_lista *b, t_lista *a, t_prg *prg)
{
	while (ft_list_length(b) > 0)
	{
		if (b->nb > prg->min_nb_a && b->nb < prg->max_nb_a)
			ft_pusha_in_a_normal(b, a);
		else if (b->nb < prg->min_nb_a)
			ft_pusha_in_a_min(b, a, prg);
		else if (b->nb > prg->max_nb_a)
			ft_pusha_in_a_max(b, a, prg);
	}
}
