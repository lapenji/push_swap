#include "push_swap.h"

void	ft_free_list(t_lista *lst)
{
	t_lista	*tmp;

	while (lst)
	{
		tmp = lst->next;
		lst->next = NULL;
		lst->prev = NULL;
		free (lst);
		lst = tmp;
		lst = lst->next;
	}
}

void	ft_free_lists(t_lista *a, t_lista *b)
{
	ft_free_list(a);
	ft_free_list(b);
}

void	ft_free_arrays(int *mova, int *movb)
{
	free(mova);
	free(movb);
}
