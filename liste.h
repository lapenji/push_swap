typedef struct s_lista
{
	int	nb;
	int idx;
	struct s_lista	*next;
	struct s_lista	*prev;
}	t_lista;

#include <stdlib.h>
int	ft_atoi(const char *nptr);
void	sa_sb(t_lista *lista);
void	rra_rrb(t_lista	*lista);
void	ra_rb(t_lista *lista);
void	pa_pb(t_lista **a, t_lista **b);
t_lista	*create_elem(int n, int i);
void	ft_add_element(t_lista **lista, int n, int i);
void	ft_remove_first(t_lista **lista);



