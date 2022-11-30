typedef struct s_lista
{
	int	nb;
	int idx;
	struct s_lista	*next;
	struct s_lista	*prev;
}	t_lista;

typedef struct s_prg
{
	int	best_lis;
	int	max_count;
	int	min_nb_a;
	int	min_nb_b;
}	t_prg;

#include <stdlib.h>
#include <stdio.h>
int	ft_atoi(const char *nptr);
void	sa_sb(t_lista *lista, char c);
void	rra_rrb(t_lista	*lista, char c);
void	ra_rb(t_lista *lista, char c);
void	pa_pb(t_lista **a, t_lista **b, char c);
t_lista	*create_elem(int n, int i);
void	ft_add_element(t_lista **lista, int n, int i);
void	ft_remove_first(t_lista **lista);
int		ft_list_length(t_lista *lista);
int		how_many_moves(t_lista *lista);
int		how_many_moves_fb(t_lista *lista);
void	ft_set_indexes(t_lista *lista);
int		ft_is_the_largest(int n, t_lista *lista);
int		ft_is_the_smallest(int n, t_lista *lista);
int		ft_doing_ra(t_lista *lista);
int		ft_doing_rra(t_lista *lista);
void	ft_lis_first(t_lista *lista, t_prg *prg);
int		ft_doing_ra_lis(t_lista *lista, int nb);
int		ft_doing_rra_lis(t_lista *lista, int nb);
void	rrab(t_lista *a, t_lista *b);
int		ft_find_min(t_lista *lista);
int		ft_find_max(t_lista *lista);
void	ft_order_lis(t_lista *lista, t_prg *prg, char c);
void	ft_pusha_in_b(t_lista **a, t_lista **b, t_prg *prg);
