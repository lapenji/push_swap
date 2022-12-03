#include "push_swap.h"
#include <stdio.h>

int	positivize(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}
int	ft_is_ordered(t_lista *lista)
{
	while (lista->next)
	{
		if (lista->nb > lista->next->nb)
			return (1);
		lista = lista->next;
	}
	return (0);
}

void	ft_print_list(t_lista *lista)
{
	while(lista)
	{
		printf("%d	", lista->idx);
		printf("%d\n", lista->nb);
		lista = lista->next;
	}
}

void	ft_solve_three(t_lista *a)
{
	if (a->nb > a->next->nb && a->next->nb < a->next->next->nb && a->nb < a->next->next->nb)
		sa_sb(a, 'a');
	else if (a->nb > a->next->nb && a->next->nb > a->next->next->nb && a->nb > a->next->next->nb)
	{
		sa_sb(a, 'a');
		rra_rrb(a, 'a');
	}
	else if (a->nb > a->next->nb && a->next->nb < a->next->next->nb && a->nb > a->next->next->nb)
		ra_rb(a, 'a');
	else if (a->nb < a->next->nb && a->next->nb > a->next->next->nb && a->nb < a->next->next->nb)
	{
		sa_sb(a, 'a');
		ra_rb(a, 'a');
	}
	else if(a->nb < a->next->nb && a->next->nb > a->next->next->nb && a->nb > a->next->next->nb)
		rra_rrb(a, 'a');
}

int	*ft_create_movb_array(t_lista *lista)
{
	int	*res;
	int	i;
	int	tmplen;

	i = 0;
	res = (int *)malloc(sizeof(int) * ft_list_length(lista));
	tmplen = ft_list_length(lista);
	while (lista)
	{
		if (i < (tmplen / 2))
			res[i] = i;
		else
			res[i] = (i - tmplen);
		i++;
		lista = lista->next;
	}
	return (res);
}

int	ft_find_best_move_ra(t_lista *a, int target, t_prg *prg)
{
	int	res;
	int	i;

	res = 0;
	prg->min_nb_a = ft_find_min(a);
	if (target < prg->min_nb_a)
	{
		while (a->nb != prg->min_nb_a)
		{
			res++;
			ra_rb(a, 0);
		}
		i = res;
		while (i > 0)
		{
			rra_rrb(a, 0);
			i--;
		}
	}
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
	{
		while (a->nb != prg->min_nb_a)
		{
			res++;
			rra_rrb(a, 0);
		}
		i = res;
		while (i > 0)
		{
			ra_rb(a, 0);
			i--;
		}
	}
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

int	*ft_create_mova_array(t_lista *a, t_lista *b, t_prg *prg)
{
	int	*res;
	int	i;
	int	ra;
	int rra;

	i = 0;
	res = (int *)malloc(sizeof(int) * ft_list_length(b));
	while (b)
	{
		ra = ft_find_best_move_ra(a, b->nb, prg);
		rra = ft_find_best_move_rra(a, b->nb, prg);
		if (positivize(ra) < positivize(rra))
			res[i] = ra;
		else
			res[i] = rra;
		i++;
		b = b->next;
	}
	return (res);
}

int	ft_find_value(int *mova, int *movb, int i)
{
	if (mova[i] >= 0 && movb[i] >= 0)
	{
		if (mova[i] > movb[i])
			return (mova[i]);
		else
			return (movb[i]);
	}
	else if (mova[i] >= 0 && movb[i] <= 0)
		return (mova[i] + positivize(movb[i]));
	else if (mova[i] <= 0 && movb[i] >= 0)
		return (positivize(mova[i]) + movb[i]);
	else
	{
		if(mova[i] < movb[i])
			return (positivize(mova[i]));
		else
			return (positivize(movb[i]));
	}
}

int	do_best_move(t_lista *b, int *mova, int *movb)
{
	int	i;
	int	x;
	int best;
	int	besti;
	int	tmp;

	besti = 0;
	i = 0;
	best = ft_find_value(mova, movb, i);
	x = ft_list_length(b);
	while (i < x)
	{
		tmp = ft_find_value(mova, movb, i);
		if (tmp < best)
		{
			best = tmp;
			besti = i;
		}
		i++;
	}
	return(besti);
}

int	main(int argc, char **argv)
{
	int	i;
	t_lista	*a;
	t_prg	prg;
	t_lista	*b;
	int *mova;
	int *movb;
	int migliore;

	i = 1;
	b = NULL;
	while (i < argc)
	{
		ft_add_element(&a, ft_atoi(argv[i]), i);
		i++;
	}
	ft_lis_first(a, &prg);
	ft_order_lis(a, 'a', prg.best_lis);
	prg.min_nb_a = ft_find_min(a);
	prg.max_nb_a = ft_find_max(a);
	ft_pusha_in_b(&a, &b, &prg);
	prg.min_nb_a = ft_find_min(a);
	prg.max_nb_a = ft_find_max(a);
	mova = ft_create_mova_array(a, b, &prg);
	i = 0;
	// ft_print_list(a);
	// printf("\n-------\n");
	// ft_print_list(b);
	// while (i < ft_list_length(b))
	// {
	// 	printf("\nbest mova = %d\n", mova[i]);
	// 	i++;
	// }
	while (ft_list_length(b) > 0)
	{
		i = 0;
		mova = ft_create_mova_array(a, b, &prg);
		movb = ft_create_movb_array(b);
		migliore = do_best_move(b, mova, movb);
		if (mova[migliore] >= 0 && movb[migliore] >= 0)
		{
			if (mova[migliore] > movb[migliore])
			{
				while (i < mova[migliore])
				{
					if (i < movb[migliore])
						rab(a, b);
					else
						ra_rb(a, 'a');
					i++;
				}
			}
			else
			{
				while (i < movb[migliore])
				{
					if (i < mova[migliore])
						rab(a, b);
					else
						ra_rb(b, 'b');
					i++;
				}
			}
		}
		else if (mova[migliore] >= 0 && movb[migliore] <= 0)
		{
			while (i < mova[migliore])
			{
				ra_rb(a, 'a');
				i++;
			}
			i = 0;
			while (i > movb[migliore])
			{
				rra_rrb(b, 'b');
				i--;
			}
		}
		else if (mova[migliore] <= 0 && movb[migliore] >= 0)
		{
			while (i > mova[migliore])
			{
				rra_rrb(a, 'a');
				i--;
			}
			i = 0;
			while (i < movb[migliore])
			{
				ra_rb(b, 'b');
				i++;
			}
		}
		else if (mova[migliore] <= 0 && movb[migliore] <= 0)
		{
			if (mova[migliore] < movb[migliore])
			{
				while (i > mova[migliore])
				{
					if (i > movb[migliore])
						rrab(a, b);
					else
						rra_rrb(a, 'a');
					i--;
				}
			}
			else
			{
				while (i > movb[migliore])
				{
					if (i > mova[migliore])
						rrab(a, b);
					else
						rra_rrb(b, 'b');
					i--;
				}
			}
		}
		pa_pb(&b, &a, 'a');
		if (a->nb > a->next->nb)
		prg.max_nb_a = ft_find_max(a);
		prg.min_nb_a = ft_find_min(a);
	}
	prg.min_nb_a = ft_find_min(a);
	while (a->nb != prg.min_nb_a)
	{
		ra_rb(a, 'a');
	}
	ft_print_list(a);
}
