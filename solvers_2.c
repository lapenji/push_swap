#include "push_swap.h"

static void	ft_solve_pos_pos(t_lista **a, t_lista **b, t_prg *prg, int migliore)
{
	int	i;

	i = 0;
	if (prg->mova[migliore] > prg->movb[migliore])
	{
		while (i < prg->mova[migliore])
		{
			if (i < prg->movb[migliore])
				rab(a, b);
			else
				ra_rb(a, 'a');
			i++;
		}
	}
	else
	{
		while (i < prg->movb[migliore])
		{
			if (i < prg->mova[migliore])
				rab(a, b);
			else
				ra_rb(b, 'b');
			i++;
		}
	}
}

static void	ft_solve_pos_neg(t_lista **a, t_lista **b, t_prg *prg, int migliore)
{
	int	i;

	i = 0;
	while (i < prg->mova[migliore])
	{
		ra_rb(a, 'a');
		i++;
	}
	i = 0;
	while (i > prg->movb[migliore])
	{
		rra_rrb(b, 'b');
		i--;
	}
}

static void	ft_solve_neg_pos(t_lista **a, t_lista **b, t_prg *prg, int migliore)
{
	int	i;

	i = 0;
	while (i > prg->mova[migliore])
	{
		rra_rrb(a, 'a');
		i--;
	}
	i = 0;
	while (i < prg->movb[migliore])
	{
		ra_rb(b, 'b');
		i++;
	}
}

static void	ft_solve_neg_neg(t_lista **a, t_lista **b, t_prg *prg, int migliore)
{
	int	i;

	i = 0;
	if (prg->mova[migliore] < prg->movb[migliore])
	{
		while (i > prg->mova[migliore])
		{
			if (i > prg->movb[migliore])
				rrab(a, b);
			else
				rra_rrb(a, 'a');
			i--;
		}
	}
	else
	{
		while (i > prg->movb[migliore])
		{
			if (i > prg->mova[migliore])
				rrab(a, b);
			else
				rra_rrb(b, 'b');
			i--;
		}
	}
}

void	ft_pusha_in_a(t_lista **a, t_lista **b, t_prg *prg)
{
	int	migliore;

	while (ft_list_length(*b) > 0)
	{
		prg->mova = ft_create_mova_array(a, b, prg);
		prg->movb = ft_create_movb_array(b);
		migliore = ft_find_best_move(b, prg);
		if (prg->mova[migliore] >= 0 && prg->movb[migliore] >= 0)
			ft_solve_pos_pos(a, b, prg, migliore);
		else if (prg->mova[migliore] >= 0 && prg->movb[migliore] <= 0)
			ft_solve_pos_neg(a, b, prg, migliore);
		else if (prg->mova[migliore] <= 0 && prg->movb[migliore] >= 0)
			ft_solve_neg_pos(a, b, prg, migliore);
		else if (prg->mova[migliore] <= 0 && prg->movb[migliore] <= 0)
			ft_solve_neg_neg(a, b, prg, migliore);
		pa_pb(b, a, 'a');
	}
}
