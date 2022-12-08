#include "checker.h"
#include <stdio.h>

int	ft_is_list_ordered(t_lista	*lst)
{
	t_lista	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
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
			write(2, "Error\n", 7);
			exit(-1);
		}
		ft_add_element(lst, tmp);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	i = 0;

	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_execute_move(t_lista **a_stack, t_lista **b_stack, char *line)
{
	if (line == NULL)
	{
		return ;
	}
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		ft_do_sa_sb(*a_stack);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		ft_do_sa_sb(*b_stack);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		ft_do_pa_pb(b_stack, a_stack);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		ft_do_pa_pb(a_stack, b_stack);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ft_do_ra_rb(a_stack);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		ft_do_ra_rb(b_stack);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_do_rra_rrb(a_stack);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_do_rra_rrb(b_stack);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		ft_do_rrr(a_stack, b_stack);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_do_rr(a_stack, b_stack);
	else
	{
		write(2, "Error:\n wrong parameter", 23);
	}
}

int	main(int argc, char **argv)
{
	// int	fd;

	// fd = open("moves.txt", O_RDONLY);

	char	*line;
	t_lista	*a_stack;
	t_lista	*b_stack;

	a_stack = NULL;
	b_stack = NULL;

	ft_populate_list(&a_stack, argc, argv);
	line = get_next_line(0);
	ft_execute_move(&a_stack, &b_stack, line);
	while (line != NULL)
	{
		line = get_next_line(0);
		ft_execute_move(&a_stack, &b_stack, line);
	}
	if (ft_is_list_ordered(a_stack) == 0)
		printf("KO\n");
	else
		printf("OK\n");
}
