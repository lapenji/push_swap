#include "push_swap.h"

// static int	ft_find_best_minimum_ra(t_lista *a, t_prg *prg)
// {
// 	int	res;

// 	res = 0;
// 	while (a->nb != prg->min_nb_a && a)
// 	{
// 		res++;
// 		a = a->next;
// 	}
// 	return (res);
// }

// static int	ft_find_best_minimum_rra(t_lista *a, t_prg *prg)
// {
// 	int	res;

// 	res = 0;
// 	a = ft_list_last(a);
// 	while (a->nb != prg->min_nb_a && a)
// 	{
// 		res++;
// 		a = a->prev;
// 	}
// 	return (res + 1);
// }

// static int	ft_find_min_ra_rra(t_lista **a, int target)
// {
// 	t_lista	*tmplist;
// 	int		res;

// 	printf("entro in min\n");
// 	res = 0;
// 	tmplist = *a;
// 	while (tmplist->nb != target)
// 	{
// 		tmplist = tmplist->next;
// 		res++;
// 	}
// 	if (res <= (ft_list_length(*a) / 2))
// 			return (res);
// 	else
// 		return((ft_list_length(*a) - res) * -1);
// }

int	ft_find_best_move_ra(t_lista **a, int target, t_prg *prg)
{
	int	res;
	t_lista	*tmpa;
	// printf("\nNUOVO NUMERO\n");
	res = 0;
	prg->min_nb_a = ft_find_min(*a);
	if (target < (*a)->nb && target > ft_list_last(*a)->nb)
	{
		// printf("GIA AL POSTO GIUSTO\n");
		return (0);
	}

	else if (target < prg->min_nb_a)
	{
		// printf("\nNUMERO MINIMO\n");
		if (ft_doing_rra_lis(*a, prg->min_nb_a) < ft_doing_ra_lis(*a, prg->min_nb_a))
			res = ((ft_doing_rra_lis(*a, prg->min_nb_a)) * - 1);
		else
			res = (ft_doing_ra_lis(*a, prg->min_nb_a));
	}
	else
	{
		// printf("NUMERO NORMALE\n");
		tmpa = *a;
		while((tmpa->nb > target || target > tmpa->next->nb) && tmpa)
		{
			//printf("\nesamino %d, res = %d, target = %d\n", tmpa->nb, res, target);
			res++;
			tmpa = tmpa->next;
		}
		res++;
		if (res >= (ft_list_length(*a) / 2))
			res = ((ft_list_length(*a) - res) * -1);
	}
	//printf("\nprima di uscire, res = %d, target = %d\n", res, target);
	return (res);
}

// int	ft_find_best_move_rra(t_lista **a, int target, t_prg *prg)
// {
// 	int	res;
// 	int	i;

// 	res = 0;
// 	prg->min_nb_a = ft_find_min(*a);
// 	if (target < prg->min_nb_a)
// 		res = ft_find_best_minimum_rra(*a, prg);
// 	else
// 	{
// 		tmpa = *a;
// 		while(tmpa->nb > target || target > tmpa->next->nb)
// 		{
// 			tmpa = tmpa->next;
// 			res++;
// 		}
// 		res++;
// 		if (res <= (ft_list_length(*a) / 2))
// 			return (res);
// 		else
// 			return(ft_list_length(*a) + 1);
// 	}
// 	return (res * -1);
// }
