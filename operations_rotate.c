/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herasoan <herasoan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:04 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/18 10:08:05 by herasoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **stack)
{
    t_list *first;
    t_list *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    last = *stack;

    while (last->next != NULL) // Trouve le dernier noeud
        last = last->next;

    *stack = first->next;      // Le 2ème devient le 1er
    first->next = NULL;        // Le 1er perd sa suite
    last->next = first;        // L'ancien dernier pointe vers l'ancien 1er
}

void ra(t_list **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void rb(t_list **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}
