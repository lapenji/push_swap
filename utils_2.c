#include "push_swap.h"

void	ft_order_lis(t_lista *lista, char c, int min)
{
	if (ft_doing_ra_lis(lista, min) < ft_doing_rra_lis(lista, min))
	{
			while (lista->nb != min)
			ra_rb(lista, c);
	}
	else
	{
		while (lista->nb != min)
			rra_rrb(lista, c);
	}
}

void	ft_pusha_in_b(t_lista **a, t_lista **b, t_prg *prg)
{
	int	tmpmax;

	tmpmax = prg->best_lis;
	while (ft_list_length(*a) > prg->max_count)
	{
		if (tmpmax <= (*a)->nb)
		{
			tmpmax = (*a)->nb;
			ra_rb(*a, 'a');
		}
		else
			pa_pb(a, b, 'b');
	}
}

// void    check_part2(t_push *tmp, t_cont *box)
// {
//     while (tmp)
//     {
//         box->path_countb++;
//         tmp = tmp->next;
//     }
//     if(box->path_counta < box->path_countb)
//         box->shortest = 0;
//     else
//         box->shortest = 1;
// }

// void    check_shortest(t_lista **head_x, t_prg *box)
// {
//     t_lista  *tmp;
// 	int path_counta;
// 	int	path_countb;

// 	path_counta = 0;
//     path_countb = 1;
//     tmp = *head_x;
//     while(tmp->nb != box->best_lis)
//     {
//         path_counta++;
//         tmp = tmp->next;
//     }
//     check_part2(tmp, box); //trovo box target
//     box->path_counta = 0;
//     box->path_countb = 1;
// }
