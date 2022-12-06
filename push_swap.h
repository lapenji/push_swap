/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:34:46 by ltombell          #+#    #+#             */
/*   Updated: 2022/12/06 18:52:10 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

//struct

typedef struct s_lista
{
	int				nb;
	struct s_lista	*next;
	struct s_lista	*prev;
}	t_lista;

typedef struct s_prg
{
	int	best_lis;
	int	max_count;
	int	min_nb_a;
	int	*mova;
	int	*movb;
}	t_prg;

//utility liste
void	ft_print_list(t_lista *lista);
void	ft_add_element(t_lista **lista, int n);
int		ft_list_length(t_lista *lista);
void	ft_add_element_to_start(t_lista **lista, int nb);
void	ft_remove_first(t_lista **lista);
t_lista	*ft_list_last(t_lista *lst);
void	ft_remove_last(t_lista **lista);
//utility varie
int		ft_atoi(const char *nptr);
int		ft_find_min(t_lista *lista);
int		ft_absolute(int nb);
int		ft_is_number(char c);
int		ft_is_the_smallest(int n, t_lista *lista);
int		ft_is_list_ordered(t_lista	*lst);
//stack utils
void	ft_populate_list(t_lista **lst, int argc, char **argv);
//lis utils
void	ft_lis_finder(t_lista *lista, t_prg *prg);
//mosse
void	sa_sb(t_lista *lista, char c);
void	ra_rb(t_lista **lista, char c);
void	rra_rrb(t_lista	**lista, char c);
void	pa_pb(t_lista **a, t_lista **b, char c);
void	rab(t_lista **a, t_lista **b);
void	rrab(t_lista **a, t_lista **b);
//solutori
void	ft_pusha_in_b(t_lista **a, t_lista **b, t_prg *prg);
void	ft_order_lis(t_lista **lista, int min);
void	ft_pusha_in_a(t_lista **a, t_lista **b, t_prg *prg);
void	ft_three_solver(t_lista **a);
void	ft_push_in_b_five_n_solve(t_lista **a, t_lista **b);

//contatori
int		ft_doing_ra_counter(t_lista *lista, int nb);
int		ft_doing_rra_counter(t_lista *lista, int nb);
int		ft_find_best_move_ra(t_lista **a, int target, t_prg *prg);
int		ft_find_best_move(t_lista **b, t_prg *prg);
//array
int		*ft_create_mova_array(t_lista **a, t_lista **b, t_prg *prg);
int		*ft_create_movb_array(t_lista **lista);
//error check
int		ft_checkinput_nbrs(int argc, char **argv);
//frees
void	ft_free_list(t_lista *lst);
void	ft_free_lists(t_lista *a, t_lista *b);

#endif
