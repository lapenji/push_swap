#include "push_swap.h"

int	ft_doing_rb_target(t_lista *a, t_lista *b, int target)
{
	int	count;
	int	d;
	t_lista	*tmp;

	tmp = b;
	count = 0;
	while (!(target < tmp->nb && target > ft_list_last(tmp)->nb))
	{
		rra_rrb(tmp, 0);
		count ++;
	}
	d = count;
	while (count > 0)
	{
		ra_rb(tmp, 0);
		count --;
	}
	return (d);
}
