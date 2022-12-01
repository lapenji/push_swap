#include "push_swap.h"

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
	if ((*lista)->next)
	{
		*lista = (*lista)->next;
		(*lista)->prev = NULL;
		free (tmp);
	}
	else (*lista) = NULL;
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

void	ft_set_indexes(t_lista *lista)
{
	int	i;
	t_lista	*tmp;

	tmp = lista;
	i = 0;
	while (tmp)
	{
		tmp->idx = i;
		i++;
		tmp = tmp->next;
	}
}

t_lista	*ft_list_last(t_lista *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
