/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:30 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/18 21:17:45 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_list
{
    int             value;
	int			index;
    struct s_list   *next;
}   t_list;

// Parsing & Erreurs
void    free_stack(t_list **stack);
void    free_matrix(char **matrix);
void    parse_arguments(t_list **a, int argc, char **argv);
void    error_exit(t_list **a, char **matrix);
int     is_numeric(char *str);
long    ft_atol(const char *str);
int     check_duplicate(t_list *a, int n);

// Opérations de base (les moteurs)
void    swap(t_list **stack);
void    push(t_list **src, t_list **dest);
void    rotate(t_list **stack);
void    rev_rotate(t_list **stack);

// Commandes (celles qui impriment et utilisent les moteurs)
void    sa(t_list **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);
void    pa(t_list **b, t_list **a);
void    pb(t_list **a, t_list **b);
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);
void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);

// Algorithmes de tri
void    append_node(t_list **stack, int n);
int     get_stack_size(t_list *stack);
int     get_min_pos(t_list *stack);
int     get_max_pos(t_list *stack);
void    index_stack(t_list *stack);
int     ft_sqrt(int number);
void	sort_simple(t_list **a, t_list **b);
void	sort_medium(t_list **a, t_list **b);
void	sort_adaptive(t_list **a, t_list **b);
double  compute_disorder(t_list *stack);

#endif
