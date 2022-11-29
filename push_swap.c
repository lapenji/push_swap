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
	t_lista	*b;
	// int	fb;
	// int ff;

	i = 1;

	b = NULL;
	while (i < argc)
	{
		ft_add_element(&a, ft_atoi(argv[i]), i);
		i++;
	}

	while (ft_list_length(a) > 3)
	{
		while (ft_is_the_smallest(a->nb, a) == 0)
		{
			if (ft_doing_ra(a) < ft_doing_rra(a))
			{
				while (ft_is_the_smallest(a->nb, a) == 0)
					ra_rb(a, 'a');
			}
			else
			{
				while (ft_is_the_smallest(a->nb, a) == 0)
					rra_rrb(a, 'a');
			}
		}
		pa_pb(&a, &b, 'b');
	}
	ft_solve_three(a);
	while (ft_list_length(b) > 0)
	{
		pa_pb(&b, &a, 'a');
	}
	// printf("\n-----------\n");
	// ft_print_list(a);
}
