/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:07:55 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/23 18:26:05 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_node **src, t_node **dest)
{
    t_node *temp;

    if (!src || !*src)
        return;
    temp = *src;
    *src = (*src)->next; // Détache le premier noeud de src

    temp->next = *dest;  // Attache ce noeud au-dessus de dest
    *dest = temp;        // Met à jour le pointeur dest
}

void pa(t_node **b, t_node **a)
{
    push(b, a);
    ft_printf("pa\n");
}

void pb(t_node **a, t_node **b)
{
    push(a, b);
    ft_printf("pb\n");
}
