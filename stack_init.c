/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herasoan <herasoan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:47 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/18 10:08:48 by herasoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Crée un noeud et l'ajoute à la fin de la pile
void append_node(t_list **stack, int n)
{
    t_list  *new_node;
    t_list  *last_node;

    if (!stack)
        return;
    new_node = malloc(sizeof(t_list));
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
