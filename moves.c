#include "liste.h"

void	sa_sb(t_lista *lista)
{
	int	swap;

	swap = lista->nb;
	lista->nb = lista->next->nb;
	lista->next->nb = swap;
}

void	rra_rrb(t_lista	*lista)
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
}

void	ra_rb(t_lista *lista)
{
	while (lista->next)
	{
		sa_sb(lista);
		lista = lista->next;
	}
}

void	pa_pb(t_lista **a, t_lista **b)
{

	int	tmp;
	tmp = (*a)->nb;
	ft_add_element(b, tmp, 0);
	ft_remove_first(a);
}
