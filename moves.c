#include "push_swap.h"

void	ra_rb(t_lista *lista, char c)
{
	while (lista->next)
	{
		sa_sb(lista, 0);
		lista = lista->next;
	}
	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
}

void	rra_rrb(t_lista	*lista, char c)
{
	int	swap;

	while (lista->next)
		lista = lista->next;
	while (lista->prev)
	{
		swap = lista->nb;
		lista->nb = lista->prev->nb;
		lista->prev->nb = swap;
		lista = lista->prev;
	}
	if (c == 'a')
		printf("rra\n");
	else if (c == 'b')
		printf("rrb\n");
}

void	pa_pb(t_lista **a, t_lista **b, char c)
{
	int	tmp;

	tmp = (*a)->nb;
	ft_add_element_to_start(b, tmp);
	ft_remove_first(a);
	if (c == 'a')
		printf("pa\n");
	else if (c == 'b')
		printf("pb\n");
}

void	rab(t_lista *a, t_lista *b)
{
	ra_rb(a, 0);
	ra_rb(b, 0);
	printf("rr\n");
}

void	rrab(t_lista *a, t_lista *b)
{
	rra_rrb(a, 0);
	rra_rrb(b, 0);
	printf("rrr\n");
}
