#include "push_swap.h"

int	*ft_create_mova_array(t_lista **a, t_lista **b, t_prg *prg)
{
	int		*res;
	int		i;
	t_lista	*tmplist;

	i = 0;
	tmplist = *b;
	res = (int *)malloc(sizeof(int) * ft_list_length(*b));
	while (*b)
	{
		res[i] = ft_find_best_move_ra(a, (*b)->nb, prg);
		i++;
		*b = (*b)->next;
	}
	*b = tmplist;
	return (res);
}

int	*ft_create_movb_array(t_lista **lista)
{
	int		*res;
	int		i;
	int		tmplen;
	t_lista	*tmplist;

	tmplist = *lista;
	i = 0;
	res = (int *)malloc(sizeof(int) * ft_list_length(tmplist));
	tmplen = ft_list_length(tmplist);
	while (tmplist)
	{
		if (i < (tmplen / 2))
			res[i] = i;
		else
			res[i] = (i - tmplen);
		i++;
		tmplist = tmplist->next;
	}
	return (res);
}
