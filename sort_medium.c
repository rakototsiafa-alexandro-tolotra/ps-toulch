/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:09:18 by arakotot          #+#    #+#             */
/*   Updated: 2026/03/23 18:26:56 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Étape 1 : Pousser dans B par blocs
static void push_chunks_to_b(t_node **a, t_node **b, int chunk_size)
{
    int pushed;
    
    pushed = 0;
    while (*a)
    {
        // Si l'élément fait partie de la première moitié du bloc actuel
        if ((*a)->index <= pushed)
        {
            pb(a, b);
            rb(b); // On l'envoie au fond de B pour laisser la place aux plus grands
            pushed++;
        }
        // Si l'élément fait partie de la deuxième moitié du bloc
        else if ((*a)->index <= pushed + chunk_size)
        {
            pb(a, b);
            pushed++;
        }
        // Pas dans le bloc, on passe au suivant
        else
        {
            ra(a);
        }
    }
}

// Étape 2 : Ramener de B vers A du plus grand au plus petit
static void push_max_to_a(t_node **a, t_node **b)
{
    int max_pos;
    int size;

    while (*b)
    {
        max_pos = get_max_pos(*b);
        size = get_stack_size(*b);
        
        if (max_pos <= size / 2)
        {
            while (max_pos-- > 0)
                rb(b);
        }
        else
        {
            max_pos = size - max_pos;
            while (max_pos-- > 0)
                rrb(b);
        }
        pa(b, a);
    }
}

// La fonction principale O(n racine de n) "chunks"
void sort_medium(t_node **a, t_node **b)
{
    int size;
    int chunk_size;

    // 1. On indexe la pile (ultra rapide en mémoire)
    index_stack(*a);
    
    size = get_stack_size(*a);
    
    // 2. On définit la taille du bloc en racine carrée (multipliée par un petit facteur pour optimiser)
    chunk_size = ft_sqrt(size) * 1.5;
    
    if (chunk_size < 1)
        chunk_size = 1;

    // 3. On exécute l'algorithme
    push_chunks_to_b(a, b, chunk_size);
    push_max_to_a(a, b);
}