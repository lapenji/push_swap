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
	ft_print_list(a);
	printf("\n-----------\n");
	ft_lis_first(a, &prg);
	printf("\nnumero migliore = %d\n", prg.best_lis);
	ft_order_lis(a, &prg, 'a');
	printf("\n-------A DOPO ORDINE\n");
	ft_print_list(a);
	printf("\n-------\n");
	ft_pusha_in_b(&a, &b, &prg);
	printf("\n-----b dopo push\n");
	ft_print_list(b);
	printf("\n-----a dopo push\n");
	ft_print_list(a);
	prg.min_nb_a = ft_find_min(a);
	prg.min_nb_b = ft_find_min(b);
	printf("minimo b %d\n", prg.min_nb_b);
	printf("\n-----b dopo findmin\n");
	ft_print_list(b);
	printf("\n-----a dopo findmin\n");
	ft_print_list(a);
	ft_order_lis(a, &prg, 'a');
	ft_order_lis(b, &prg, 'b');
	printf("\n-----a dopo ordine\n");
	ft_print_list(a);
	printf("\n-----b dopo ordine\n");
	ft_print_list(b);
	// while (ft_list_length(b) > 0)
	// {
	// 	printf("\n voglio spostare %d, in a ho %d \n", b->nb, a->nb);
	// 	if (b->nb < prg.min_nb_a)
	// 		pa_pb(&b, &a, 'a');
	// 	else
	// 	{
	// 		while (b->nb > a->nb)
	// 			ra_rb(a, 'a');
	// 		pa_pb(&b, &a, 'a');
	// 	}
	// }
	// while (ft_list_length(b) > 0)
	// {
	// 	printf("provo %d, %d\n", a->nb, b->nb);
	// 	if (b->nb < a->nb && b->nb > a->next->nb)
	// 		pa_pb(&b, &a, 'a');
	// 	else
	// 		ra_rb(a, 'b');
	// }
	// while (ft_list_length(a) > 3)
	// {
	// 	while (ft_is_the_smallest(a->nb, a) == 0)
	// 	{
	// 		if (ft_doing_ra(a) < ft_doing_rra(a))
	// 		{
	// 			while (ft_is_the_smallest(a->nb, a) == 0)
	// 				ra_rb(a, 'a');
	// 		}
	// 		else
	// 		{
	// 			while (ft_is_the_smallest(a->nb, a) == 0)
	// 				rra_rrb(a, 'a');
	// 		}
	// 	}
	// 	pa_pb(&a, &b, 'b');
	// }
	// ft_solve_three(a);
	// while (ft_list_length(b) > 0)
	// {
	// 	pa_pb(&b, &a, 'a');
	// }
	// printf("%d, %d\n", prg.best_lis, prg.max_count);
	// printf("\n-----------a\n");
/* 	ft_print_list(a);
	printf("\n-----------b\n");
	ft_print_list(b); */
}
