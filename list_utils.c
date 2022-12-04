#include "push_swap.h"

static t_lista	*create_elem(int n)
{
	t_lista	*elem;

	elem = (t_lista *)malloc(sizeof(t_lista));
	elem->nb = n;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	ft_add_element(t_lista **lista, int n)
{
	t_lista	*new;
	t_lista	*tmp;

	tmp = *lista;
	if (!*lista)
		*lista = create_elem(n);
	else
	{
		while (tmp->next)
		tmp = tmp->next;
		new = create_elem(n);
		tmp->next = new;
		new->prev = tmp;
	}
}

void	ft_print_list(t_lista *lista)
{
	while (lista)
	{
		printf("%d\n", lista->nb);
		lista = lista->next;
	}
}

int	ft_list_length(t_lista *lista)
{
	t_lista	*tmp;
	int		i;

	i = 0;
	tmp = lista;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_add_element_to_start(t_lista **lista, int nb)
{
	t_lista	*new;

	new = create_elem(nb);
	if (!*lista)
		*lista = new;
	else
	{
		new->next = (*lista);
		(*lista)->prev = new;
		*lista = new;
	}
}
