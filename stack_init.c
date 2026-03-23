/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:47 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/23 18:27:05 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Crée un noeud et l'ajoute à la fin de la pile
void append_node(t_node **stack, int n)
{
    t_node  *new_node;
    t_node  *last_node;

    if (!stack)
        return;
    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = n;
    new_node->next = NULL;

    // Si la pile est vide, le nouveau noeud devient le premier
    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    // Sinon, on cherche le dernier noeud pour l'attacher à la fin
    last_node = *stack;
    while (last_node->next != NULL)
        last_node = last_node->next;
    last_node->next = new_node;
}
