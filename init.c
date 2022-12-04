#include "push_swap.h"

static int	ft_check_for_doubles(t_lista *list, int nb)
{
	t_lista	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_populate_list(t_lista **lst, int argc, char **argv)
{
	int	i;
	int	tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (ft_check_for_doubles(*lst, tmp) == 1)
		{
			perror("numero doppio");
			ft_free_list(*lst);
			exit (EXIT_FAILURE);
		}
		ft_add_element(lst, ft_atoi(argv[i]));
		i++;
	}
}

int	ft_checkinput_nbrs(int argc, char **argv)
{
	int	i;
	int	b;

	i = 0;
	b = 1;
	while (b < argc)
	{
		while (argv[b][i])
		{
			if (ft_is_number(argv[b][i]) == 0)
				return (1);
			i++;
		}
		i = 0;
		b++;
	}
	return (0);
}
