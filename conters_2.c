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
		if(prg->mova[i] < prg->movb[i])
			return (ft_absolute(prg->mova[i]));
		else
			return (ft_absolute(prg->movb[i]));
	}
}

int	ft_find_best_move(t_lista *b, t_prg *prg)
{
	int	i;
	int	x;
	int best;
	int	besti;
	int	tmp;

	besti = 0;
	i = 0;
	best = ft_find_value(prg, i);
	x = ft_list_length(b);
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
	return(besti);
}
