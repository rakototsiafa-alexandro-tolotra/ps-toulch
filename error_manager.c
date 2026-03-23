/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:07:38 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/23 18:25:55 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Libère chaque noeud de la pile
void free_stack(t_node **stack)
{
    t_node *tmp;

    if (!stack || !*stack)
        return;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

// Libère le tableau 2D créé par ft_split
void free_matrix(char **matrix)
{
    int i;

    i = 0;
    if (!matrix || !*matrix)
        return;
    while (matrix[i])
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

// Nettoie tout et quitte proprement
void error_exit(t_node **a, char **matrix)
{
    if (a && *a)
        free_stack(a);
    if (matrix)
        free_matrix(matrix);
    // Le sujet exige d'afficher sur la sortie d'erreur (stderr = 2)
    write(2, "Error\n", 6);
    exit(1);
}
