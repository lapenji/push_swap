#include "liste.h"

t_lista	*create_elem(int n, int i)
{
	t_lista	*elem;
	elem = (t_lista *)malloc(sizeof(t_lista));
	elem->nb = n;
	elem->idx = i;
	elem->next = NULL;
	elem->prev = NULL;
	return(elem);
}

void	ft_add_element(t_lista **lista, int n, int i)
{
	t_lista	*new;
	t_lista *tmp;

	tmp = *lista;
	if (!*lista)
		*lista = create_elem(n , i);
	else
	{
	while (tmp->next)
		tmp = tmp->next;
	new = create_elem(n, i);
	tmp->next = new;
	new->prev = tmp;
	}
}

void	ft_remove_first(t_lista **lista)
{
	t_lista	*tmp;

	tmp = *lista;
	*lista = (*lista)->next;
	(*lista)->prev = NULL;
	free (tmp);
	tmp = *lista;
	while (tmp)
	{
		tmp->idx -= 1;
		tmp = tmp->next;
	}
}
