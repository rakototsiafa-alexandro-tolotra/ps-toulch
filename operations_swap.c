/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:11 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/24 00:30:09 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Le moteur logique
void swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

// Les commandes qui utilisent le moteur et impriment
void sa(t_node **a)
{
    swap(a);
    ft_printf("sa\n");
}

void sb(t_node **b)
{
    swap(b);
    ft_printf("sb\n");
}

void ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}
