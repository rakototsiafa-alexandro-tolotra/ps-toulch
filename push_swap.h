/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:30 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/23 22:49:27 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* Parsing & Erreurs */
void	free_stack(t_node **stack);
void	free_matrix(char **matrix);
void	parse_arguments(t_node **a, int argc, char **argv);
void	error_exit(t_node **a, char **matrix);
int		is_numeric(char *str);
long	ft_atol(const char *str);
int		check_duplicate(t_node *a, int n);

/* Opérations de base (moteurs, sans affichage) */
void	swap(t_node **stack);
void	push(t_node **src, t_node **dest);
void	rotate(t_node **stack);
void	rev_rotate(t_node **stack);

/* Commandes (affichent l'opération via ft_printf) */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **b, t_node **a);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* Utilitaires pile */
void	append_node(t_node **stack, int n);
int		get_stack_size(t_node *stack);
int		get_min_pos(t_node *stack);
int		get_max_pos(t_node *stack);
int		get_max_pos_by_value(t_node *stack);
void	index_stack(t_node *stack);
int		ft_sqrt(int number);

/* Algorithmes de tri */
void	sort_simple(t_node **a, t_node **b);
void	sort_medium(t_node **a, t_node **b);
void	sort_complex(t_node **a, t_node **b);
void	sort_adaptive(t_node **a, t_node **b);

/* Mesure du désordre */
double	compute_disorder(t_node *stack_a);

#endif