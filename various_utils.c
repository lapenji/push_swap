#include "push_swap.h"

int	how_many_moves(t_lista *lista)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = lista->nb;
	while (lista->next)
	{
		if (tmp < lista->next->nb)
			return(i);
		lista = lista->next;
		i++;
	}
	return (i);
}

int	how_many_moves_fb(t_lista *lista)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = lista->nb;
	while (lista->next)
	{
		lista = lista->next;
	}
	printf("%d sono arrivato a\n", lista->nb);
	while (lista->prev)
	{
		if (tmp > lista->nb)
			return (i);
		i++;
		lista = lista->prev;
	}
	return (i);
}
