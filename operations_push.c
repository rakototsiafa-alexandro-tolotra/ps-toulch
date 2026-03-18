/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herasoan <herasoan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:07:55 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/18 10:07:57 by herasoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **src, t_list **dest)
{
    t_list *temp;

    if (!src || !*src)
        return;
    temp = *src;
    *src = (*src)->next; // Détache le premier noeud de src

    temp->next = *dest;  // Attache ce noeud au-dessus de dest
    *dest = temp;        // Met à jour le pointeur dest
}

void pa(t_list **b, t_list **a)
{
    push(b, a);
    ft_printf("pa\n");
}

void pb(t_list **a, t_list **b)
{
    push(a, b);
    ft_printf("pb\n");
}
