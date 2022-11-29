#include "push_swap.h"

void	sa_sb(t_lista *lista, char c)
{
	int	swap;

	swap = lista->nb;
	lista->nb = lista->next->nb;
	lista->next->nb = swap;
	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
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

void	ft_add_element_to_start(t_lista **lista, int nb, int idx)
{
	t_lista	*new;

	new = create_elem(nb, idx);
	if (!*lista)
		*lista = new;
	else
	{
		new->next = (*lista);
		(*lista)->prev = new;
		*lista = new;
	}
}

void	pa_pb(t_lista **a, t_lista **b, char c)
{
	int	tmp;
	tmp = (*a)->nb;
	ft_add_element_to_start(b, tmp, 0);
	ft_remove_first(a);
	if (c == 'a')
		printf("pa\n");
	else if (c == 'b')
		printf("pb\n");
}
