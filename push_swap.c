#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lista	*a_stack;
	t_lista	*b_stack;
	t_prg	prg;

	a_stack = NULL;
	b_stack = NULL;
	ft_populate_list(&a_stack, argc, argv);
	ft_lis_finder(a_stack, &prg);
	ft_order_lis(a_stack, prg.best_lis);
	ft_pusha_in_b(&a_stack, &b_stack, &prg);
	ft_pusha_in_a(&a_stack, &b_stack, &prg);
	prg.min_nb_a = ft_find_min(a_stack);
	ft_order_lis(a_stack, prg.min_nb_a);
	ft_print_list(a_stack);
}
