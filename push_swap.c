#include "push_swap.h"
#include <stdio.h>

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
	while (ft_list_length(b) > 0)
	{
		if(b->nb > prg.min_nb_a && b->nb < prg.max_nb_a)
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
		else if (b->nb < prg.min_nb_a)
		{
			if (ft_doing_ra_case_2(a, prg.min_nb_a) < ft_doing_rra_case_2(a, prg.min_nb_a))
			{
				while (a->nb != prg.min_nb_a)
					ra_rb(a, 'a');
			}
			else
			{
				while (a->nb != prg.min_nb_a)
					rra_rrb(a, 'a');
			}
			pa_pb(&b, &a , 'a');
			prg.min_nb_a = ft_find_min(a);
		}
		else if (b->nb > prg.max_nb_a)
		{
			if (ft_doing_ra_case_2(a, prg.max_nb_a) < ft_doing_rra_case_2(a, prg.max_nb_a))
			{
				while (a->nb != prg.max_nb_a)
					ra_rb(a, 'a');
			}
			else
			{
				while (a->nb != prg.max_nb_a)
					rra_rrb(a, 'a');
			}
			pa_pb(&b, &a, 'b');
			prg.max_nb_a = ft_find_max(a);
		}
	}

	prg.min_nb_a = ft_find_min(a);
	while (a->nb != prg.min_nb_a)
	{
		ra_rb(a, 'a');
	}
}
