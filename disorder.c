/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:07:30 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/23 18:25:50 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calcule le taux de désordre entre 0.0 et 1.0
double compute_disorder(t_node *stack_a)
{
    t_node  *i;
    t_node  *j;
    double  mistakes;
    double  total_pairs;

    if (!stack_a || !stack_a->next)
        return (0.0); // Une pile vide ou d'un seul élément est déjà triée

    mistakes = 0.0;
    total_pairs = 0.0;
    i = stack_a;
    while (i)
    {
        j = i->next; // On compare 'i' avec tous les éléments qui le suivent
        while (j)
        {
            total_pairs++;
            if (i->value > j->value) // Si le nombre précédent est plus grand, c'est une erreur
                mistakes++;
            j = j->next;
        }
        i = i->next;
    }

    if (total_pairs == 0.0)
        return (0.0);
    return (mistakes / total_pairs); // Retourne le pourcentage de désordre
}
