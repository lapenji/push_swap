#include "liste.h"
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
	else if (a->nb > a->next->nb && a->next->nb > a->next->next->nb)
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
	else if(a->nb < a->next->nb && a->next->nb > a->next->next->nb && a->nb < a->next->next->nb)
		rra_rrb(a);
}


int	main(int argc, char **argv)
{
	int	i;
	int c;
	t_lista	*a;
	//t_lista	*b;

	i = 0;
	c = 1;

	//b = malloc(sizeof(t_lista *));
	while (i < argc - 1)
	{
		ft_add_element(&a, ft_atoi(argv[c]), i);
		i++;
		c++;
	}
	ft_print_list(a);
	ft_solve_three(a);
	printf("\n ------------------ \n");
	printf("is ordered %d\n", ft_is_ordered(a));
	printf("\n ------------------ \n");
	ft_print_list(a);
}
