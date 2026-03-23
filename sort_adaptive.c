/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:39 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/23 18:26:45 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Le chef d'orchestre du mode adaptatif
void sort_adaptive(t_node **a, t_node **b)
{
    double disorder;

    // 1. On mesure le désordre AVANT de faire le moindre mouvement
    disorder = compute_disorder(*a);

    // 2. On choisit la bonne stratégie selon les seuils du sujet
    if (disorder < 0.2)
    {
        // Désordre faible : on lance l'algorithme simple O(n^2)
        sort_simple(a, b);
    }
    else if (disorder >= 0.2 && disorder < 0.5)
    {
        // Désordre moyen : on lance l'algorithme moyen O(n racine de n)
        sort_medium(a, b);
    }
    else
    {
        // Désordre élevé (>= 0.5) : on lance l'algorithme complexe O(n log n)
        // sort_complex(a, b);
    }
}
