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
	int		tmp;
	t_lista	*temphead;

	temphead = (*lista)->next;
	tmp = (*lista)->nb;
	ft_add_element(lista, tmp);
	ft_remove_first(lista);
	*lista = temphead;
}

void	ft_do_rra_rrb(t_lista **lista)
{
	int	tmp;

	if (ft_list_length(*lista) == 1)
		return ;
	tmp = ft_list_last(*lista)->nb;
	ft_add_element_to_start(lista, tmp);
	ft_remove_last(lista);
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
