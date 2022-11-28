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
		sa_sb(a);
	else if (a->nb > a->next->nb && a->next->nb > a->next->next->nb && a->nb > a->next->next->nb)
	{
		sa_sb(a);
		rra_rrb(a);
	}
	else if (a->nb > a->next->nb && a->next->nb < a->next->next->nb && a->nb > a->next->next->nb)
		ra_rb(a);
	else if (a->nb < a->next->nb && a->next->nb > a->next->next->nb && a->nb < a->next->next->nb)
	{
		sa_sb(a);
		ra_rb(a);
	}
	else if(a->nb < a->next->nb && a->next->nb > a->next->next->nb && a->nb > a->next->next->nb)
		rra_rrb(a);
}


int	main(int argc, char **argv)
{
	int	i;
	int c;
	t_lista	*a;
	t_lista	*b;
	int	fb;
	int ff;

	i = 0;
	c = 1;

	b = malloc(sizeof(t_lista *));
	ft_remove_first(&b);
	while (i < argc - 1)
	{
		ft_add_element(&a, ft_atoi(argv[c]), i);
		i++;
		c++;
	}
	ft_print_list(a);
	printf("\n-------------------\n");
	if (ft_list_length(a) > 3)
	{
		while (ft_list_length(a) > 3)
		{
			pa_pb(&a, &b);
		}
	}
	printf("\n----lista b-----\n");
	ft_print_list(b);
	ft_solve_three(a);
	printf("\n-----lista a---\n");
	ft_print_list(a);
	while (ft_list_length(b) > 0)
	{
		pa_pb(&b, &a);
		printf("lista b\n");
		ft_print_list(b);
		printf("lista a\n");
		ft_print_list(a);
		if (ft_is_ordered(a) != 0)
		{
			ff = how_many_moves(a);
			fb = how_many_moves_fb(a);
			printf("\nda dietro %d da davanti %d\n", fb, ff);
			if (ff < fb)
			{
				while (i <= ff)
				{
					sa_sb(a);
					i++;
				}
			}
			else
			{
				while (i < fb + 1)
				{
					printf("ruoto\n");
					ra_rb(a);
					i++;
				}
			}
		}
	}

	printf("\n ------------------ \n");
	ft_print_list(a);
}
