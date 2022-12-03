#include "push_swap.h"

void	ft_populate_list(t_lista **lst, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_add_element(lst, ft_atoi(argv[i]));
		i++;
	}
}
