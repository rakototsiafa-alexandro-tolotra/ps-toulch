/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:44 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/18 11:49:52 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// La stratégie Simple (Tri par sélection adapté)
void sort_simple(t_list **a, t_list **b)
{
    int size;
    int min_pos;

    size = get_stack_size(*a);
    while (size > 0)
    {
        min_pos = get_min_position(*a);
        // Si le minimum est dans la première moitié, on tourne vers le haut (ra)
        if (min_pos <= size / 2)
        {
            while (min_pos > 0)
            {
                ra(a); // Appelle la fonction qui fait l'action et imprime "ra" via ft_printf
                min_pos--;
            }
        }
        // S'il est dans la deuxième moitié, c'est plus court de tourner vers le bas (rra)
        else
        {
            min_pos = size - min_pos; // Calcule le nombre de coups restants par le bas
            while (min_pos > 0)
            {
                rra(a); // Imprime "rra" via ft_printf
                min_pos--;
            }
        }
        // Le minimum est maintenant au sommet, on l'envoie sur B
        pb(a, b);
        size--;
    }

    // La pile A est vide, la pile B est triée à l'envers. On remet tout dans A.
    while (*b)
        pa(b, a);
}
