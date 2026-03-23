/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:49:07 by arakotot          #+#    #+#             */
/*   Updated: 2026/03/18 20:49:07 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calcule de combien de bits (0 ou 1) on a besoin pour écrire le plus grand index
static int get_max_bits(int max_index)
{
    int max_bits;

    max_bits = 0;
    while ((max_index >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

// L'algorithme Radix Sort adapté pour push_swap (O(n log n))
void sort_complex(t_node **a, t_node **b)
{
    int size;
    int max_bits;
    int i;
    int j;

    // 1. On indexe la pile (ex: les nombres deviennent 0, 1, 2... N-1)
    index_stack(*a);
    size = get_stack_size(*a);
    
    // Le plus grand index est toujours (taille - 1)
    max_bits = get_max_bits(size - 1);

    i = 0;
    // On boucle sur chaque bit (de 0 jusqu'au bit maximum nécessaire)
    while (i < max_bits)
    {
        j = 0;
        // Pour chaque bit, on fait un tour complet de la pile A
        while (j < size)
        {
            // On décale les bits vers la droite de 'i' positions
            // et on utilise le masque '& 1' pour isoler le dernier bit.
            if (((*a)->index >> i) & 1)
                ra(a);     // Si le bit est 1, on garde dans A
            else
                pb(a, b);  // Si le bit est 0, on envoie dans B
            j++;
        }
        
        // À la fin du tour, on ramène tout de B vers A en gardant l'ordre
        while (*b)
            pa(b, a);
            
        i++; // On passe au bit suivant (vers la gauche)
    }
}