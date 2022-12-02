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
		if (i <= (tmplen / 2))
			res[i] = i;
		else
			res[i] = (i - tmplen);
		i++;
		lista = lista->next;
	}
	return (res);
}

int	*ft_create_mova_array(t_lista *a, t_lista *b, t_prg *prg)
{
	int	*res;
	int	i;

	i = 0;
	res = (int *)malloc(sizeof(int) * ft_list_length(b));
	while (b)
	{
		if(b->nb > prg->min_nb_a && b->nb < prg->max_nb_a)
		{
			if (ft_doing_ra_target(a, b->nb) < ft_doing_rra_target(a, b->nb))
				res[i] = ft_doing_ra_target(a, b->nb);
			else
				res[i] = ft_doing_rra_target(a, b->nb) * -1;
		}
		else if (b->nb < prg->min_nb_a)
		{
			if (ft_doing_ra_case_2(a, prg->min_nb_a) < ft_doing_rra_case_2(a, prg->min_nb_a))
				res[i] = ft_doing_ra_case_2(a, prg->min_nb_a);
			else
				res[i] = ft_doing_rra_case_2(a, prg->min_nb_a) * -1;
		}
		else if (b->nb > prg->max_nb_a)
		{
			if (ft_doing_ra_case_2(a, prg->min_nb_a) < ft_doing_rra_case_2(a, prg->min_nb_a))
				res[i] = ft_doing_ra_case_2(a, prg->max_nb_a);
			else
				res[i] = ft_doing_rra_case_2(a, prg->max_nb_a) * -1;
		}
		i++;
		b = b->next;
	}
	return (res);
}

int	do_best_move(t_lista *b, int *mova, int *movb)
{
	int	i;
	int	x;
	int best;
	int	besti;

	besti = 2147483647;
	i = 0;
	best = 2147483647;
	x = ft_list_length(b);
	while (i < x)
	{
		if (positivize(mova[i]) + positivize(movb[i]) < best)
		{
			best = positivize(mova[i]) + positivize(movb[i]);
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
	int *mova = ft_create_mova_array(a, b, &prg);
	int *movb = ft_create_movb_array(b);
	int migliore = do_best_move(b, mova, movb);
	//ft_pusha_in_a(b, a, &prg);
	// while (ft_list_length(b) > 0)
	// {
	// 	if(b->nb > prg.min_nb_a && b->nb < prg.max_nb_a)
	// 	{
	// 		if (ft_doing_ra_target(a, b->nb) < ft_doing_rra_target(a, b->nb))
	// 		{
	// 			while (!(b->nb < a->nb && b->nb > ft_list_last(a)->nb))
	// 				ra_rb(a, 'a');
	// 			pa_pb(&b, &a, 'a');
	// 			rra_rrb(a, 'a');
	// 		}
	// 		else
	// 		{
	// 			while (!(b->nb < a->nb && b->nb > ft_list_last(a)->nb))
	// 				rra_rrb(a, 'a');
	// 			pa_pb(&b, &a, 'a');
	// 			ra_rb(a, 'a');
	// 		}
	// 	}
	// 	else if (b->nb < prg.min_nb_a)
	// 	{
	// 		if (ft_doing_ra_case_2(a, prg.min_nb_a) < ft_doing_rra_case_2(a, prg.min_nb_a))
	// 		{
	// 			while (a->nb != prg.min_nb_a)
	// 				ra_rb(a, 'a');
	// 		}
	// 		else
	// 		{
	// 			while (a->nb != prg.min_nb_a)
	// 				rra_rrb(a, 'a');
	// 		}
	// 		pa_pb(&b, &a , 'a');
	// 		prg.min_nb_a = ft_find_min(a);
	// 	}
	// 	else if (b->nb > prg.max_nb_a)
	// 	{
	// 		if (ft_doing_ra_case_2(a, prg.max_nb_a) < ft_doing_rra_case_2(a, prg.max_nb_a))
	// 		{
	// 			while (a->nb != prg.max_nb_a)
	// 				ra_rb(a, 'a');
	// 		}
	// 		else
	// 		{
	// 			while (a->nb != prg.max_nb_a)
	// 				rra_rrb(a, 'a');
	// 		}
	// 		pa_pb(&b, &a, 'b');
	// 		prg.max_nb_a = ft_find_max(a);
	// 	}
	// }
	int movetmp;
	int	flag;
	while (ft_list_length(b) > 0)
	{
		flag = 0;
		mova = ft_create_mova_array(a, b, &prg);
		movb = ft_create_movb_array(b);
		migliore = do_best_move(b, mova, movb);
		if (mova[migliore] < 0)
		{
			movetmp = mova[migliore];
			while (movetmp < 0)
			{
				rra_rrb(a, 'a');
				movetmp ++;
			}
			flag = 1;
		}
		else if (mova[migliore > 0])
		{
			movetmp = mova[migliore];
			while (movetmp > 0)
			{
				ra_rb(a, 'a');
				movetmp --;
			}
			flag = 2;
		}
		mova[migliore] = 0;
		if (movb[migliore] < 0)
		{
			movetmp = movb[migliore];
			while (movetmp < 0)
			{
				rra_rrb(b, 'b');
				movetmp ++;
			}
		}
		else if (movb[migliore > 0])
		{
			movetmp = movb[migliore];
			while (movetmp > 0)
			{
				ra_rb(b, 'b');
				movetmp --;
			}
		}
		pa_pb(&b, &a, 'a');
		if (flag == 1)
			rra_rrb(a, 'a');
		if (flag == 2)
			ra_rb(a, 'a');
		prg.max_nb_a = ft_find_max(a);
		prg.min_nb_a = ft_find_min(a);
	}
	prg.min_nb_a = ft_find_min(a);
	while (a->nb != prg.min_nb_a)
	{
		ra_rb(a, 'a');
	}
	// ft_print_list(a);
}
