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
	while (lista->prev)
	{
		if (tmp > lista->nb)
			return (i);
		i++;
		lista = lista->prev;
	}
	return (i);
}

int	ft_is_the_largest(int n, t_lista *lista)
{
	t_lista	*tmp;

	tmp = lista;
	while (tmp)
	{
		if (tmp->nb > n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_is_the_smallest(int n, t_lista *lista)
{
	t_lista	*tmp;

	tmp = lista;
	while (tmp)
	{
		if (tmp->nb < n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_doing_ra(t_lista *lista)
{
	int	i;
	int	b;
	t_lista	*tmp;

	i = 0;
	tmp = lista;
	while (ft_is_the_smallest(lista->nb, lista) == 0)
	{
		ra_rb(lista, 0);
		i++;
	}
	b = i;
	while (i > 0)
	{
		rra_rrb(lista, 0);
		i--;
	}
	return (b);
}

int	ft_doing_ra_case_2(t_lista *lista, int target)
{
	int i;
	int b;
	i = 0;

	while (lista->nb != target)
	{
		ra_rb(lista, 0);
		i++;
	}
	b = i;
	while (i > 0)
	{
		rra_rrb(lista, 0);
		i--;
	}
	return (b);
}

int	ft_doing_rra_case_2(t_lista *lista, int target)
{
	int i;
	int b;
	i = 0;

	while (lista->nb != target)
	{
		rra_rrb(lista, 0);
		i++;
	}
	b = i;
	while (i > 0)
	{
		ra_rb(lista, 0);
		i--;
	}
	return (b);
}

int	ft_doing_ra_target(t_lista *lista, int target)
{
	int	count;
	int	b;
	t_lista	*tmp;

	tmp = lista;
	count = 0;
	while (!(target < tmp->nb && target > ft_list_last(tmp)->nb))
	{
		ra_rb(tmp, 0);
		count ++;
	}
	b = count;
	while (count > 0)
	{
		rra_rrb(tmp, 0);
		count --;
	}
	return (b);
}

int ft_doing_rra_target(t_lista *lista, int target)
{
	int	count;
	int	b;
	t_lista	*tmp;

	tmp = lista;
	count = 0;
	while (!(target < tmp->nb && target > ft_list_last(tmp)->nb))
	{
		rra_rrb(tmp, 0);
		count ++;
	}
	b = count;
	while (count > 0)
	{
		ra_rb(tmp, 0);
		count --;
	}
	return (b);
}

int	ft_doing_rra(t_lista *lista)
{
	int	i;
	int	b;
	t_lista	*tmp;

	i = 0;
	tmp = lista;
	while (ft_is_the_smallest(lista->nb, lista) == 0)
	{
		rra_rrb(lista, 0);
		i++;
	}
	b = i;
	while (i > 0)
	{
		ra_rb(lista, 0);
		i--;
	}
	return (b);
}

int	ft_doing_ra_lis(t_lista *lista, int nb)
{
	int	i;
	int	b;
	t_lista	*tmp;

	i = 0;
	tmp = lista;
	while (lista->nb != nb)
	{
		ra_rb(lista, 0);
		i++;
	}
	b = i;
	while (i > 0)
	{
		rra_rrb(lista, 0);
		i--;
	}
	return (b);
}

int	ft_doing_rra_lis(t_lista *lista, int nb)
{
	int	i;
	int	b;
	t_lista	*tmp;

	i = 0;
	tmp = lista;
	while (tmp->nb != nb)
	{
		rra_rrb(lista, 0);
		i++;
	}
	b = i;
	while (i > 0)
	{
		ra_rb(lista, 0);
		i--;
	}
	return (b);
}
