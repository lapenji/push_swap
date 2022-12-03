#include "push_swap.h"

int	*ft_create_mova_array(t_lista *a, t_lista *b, t_prg *prg)
{
	int	*res;
	int	i;
	int	ra;
	int rra;

	i = 0;
	res = (int *)malloc(sizeof(int) * ft_list_length(b));
	while (b)
	{
		ra = ft_find_best_move_ra(a, b->nb, prg);
		rra = ft_find_best_move_rra(a, b->nb, prg);
		if (ft_absolute(ra) < ft_absolute(rra))
			res[i] = ra;
		else
			res[i] = rra;
		i++;
		b = b->next;
	}
	return (res);
}

int	*ft_create_movb_array(t_lista *lista)
{
	int	*res;
	int	i;
	int	tmplen;

	i = 0;
	res = (int *)malloc(sizeof(int) * ft_list_length(lista));
	tmplen = ft_list_length(lista);
	while (lista)
	{
		if (i < (tmplen / 2))
			res[i] = i;
		else
			res[i] = (i - tmplen);
		i++;
		lista = lista->next;
	}
	return (res);
}
