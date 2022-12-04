#include "push_swap.h"

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
	else
	(*lista) = NULL;
}

t_lista	*ft_list_last(t_lista *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
