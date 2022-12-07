#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_lista
{
	int				nb;
	struct s_lista	*next;
	struct s_lista	*prev;
}	t_lista;

//list utils
void	ft_add_element_to_start(t_lista **lista, int nb);
void	ft_add_element(t_lista **lista, int n);
void	ft_remove_first(t_lista **lista);
int		ft_list_length(t_lista *lista);
void	ft_remove_last(t_lista **lista);
t_lista	*ft_list_last(t_lista *lst);

//moves
void	ft_do_pa_pb(t_lista **a, t_lista **b);
void	ft_do_ra_rb(t_lista **lista);
void	ft_do_rra_rrb(t_lista **lista);
void	ft_do_sa_sb(t_lista *lista);
void	ft_do_rr(t_lista **a, t_lista **b);
void	ft_do_rrr(t_lista **a, t_lista **b);

#endif
