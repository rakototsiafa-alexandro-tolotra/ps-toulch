/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herasoan <herasoan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:11 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/18 10:08:13 by herasoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Le moteur logique
void swap(t_list **stack)
{
    t_list *first;
    t_list *second;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

// Les commandes qui utilisent le moteur et impriment
void sa(t_list **a)
{
    swap(a);
    ft_printf("sa\n");
}

void sb(t_list **b)
{
    swap(b);
    ft_printf("sb\n");
}

void ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}
