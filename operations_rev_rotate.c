/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:01 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/23 18:26:10 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rev_rotate(t_node **stack)
{
    t_node *prev;
    t_node *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    prev = NULL;
    last = *stack;

    while (last->next != NULL) // On descend jusqu'à l'avant-dernier et dernier
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;         // L'avant-dernier devient le dernier
    last->next = *stack;       // Le dernier pointe vers le 1er actuel
    *stack = last;             // Le dernier devient officiellement le 1er
}

void rra(t_node **a)
{
    rev_rotate(a);
    ft_printf("rra\n");
}

void rrb(t_node **b)
{
    rev_rotate(b);
    ft_printf("rrb\n");
}

void rrr(t_node **a, t_node **b)
{
    rev_rotate(a);
    rev_rotate(b);
    ft_printf("rrr\n");
}
