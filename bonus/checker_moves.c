#include "checker.h"

void	ft_do_pa_pb(t_lista **a, t_lista **b)
{
	int	tmp;

	tmp = (*a)->nb;
	ft_add_element_to_start(b, tmp);
	ft_remove_first(a);
}

void	ft_do_ra_rb(t_lista **lista)
{
	t_lista	*tmp;
	t_lista	*putback;

	if ((*lista)->next != NULL)
	{
		putback = *lista;
		tmp = *lista;
		while (tmp->next)
			tmp = tmp->next;
		*lista = (*lista)->next;
		tmp->next = putback;
		putback->next = NULL;
		putback->prev = tmp;
	}
}

void	ft_do_rra_rrb(t_lista **head)
{
	t_lista	*tmp;
	t_lista	*prev;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	else
	{
		tmp = *head;
		prev = *head;
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *head;
		tmp->prev = NULL;
		tmp->next->prev = tmp;
		*head = tmp;
	}
}

void	ft_do_sa_sb(t_lista *lista)
{
	int	swap;

	swap = lista->nb;
	lista->nb = lista->next->nb;
	lista->next->nb = swap;
}

void	ft_do_rr(t_lista **a, t_lista **b)
{
	ft_do_ra_rb(a);
	ft_do_ra_rb(b);
}

void	ft_do_rrr(t_lista **a, t_lista **b)
{
	ft_do_rra_rrb(a);
	ft_do_rra_rrb(b);
}
