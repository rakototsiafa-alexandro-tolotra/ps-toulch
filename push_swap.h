/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herasoan <herasoan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:30 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/18 10:08:34 by herasoan         ###   ########.fr       */
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
    struct s_list   *next;
}   t_list;

// --- Prototypes Parsing & Erreurs ---
void    free_stack(t_list **stack);
void    free_matrix(char **matrix);
void    error_exit(t_list **a, char **matrix);

int     is_numeric(char *str);
long    ft_atol(const char *str);
int     check_duplicate(t_list *a, int n);

void    append_node(t_list **stack, int n);
void    parse_arguments(t_list **a, int argc, char **argv);

// Prototypes des opérations de base (les moteurs)
void    swap(t_list **stack);
void    push(t_list **src, t_list **dest);
void    rotate(t_list **stack);
void    rev_rotate(t_list **stack);

// Prototypes des commandes (celles qui impriment et utilisent les moteurs)
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

#endif
