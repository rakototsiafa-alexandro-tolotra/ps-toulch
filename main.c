/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:55:56 by arakotot          #+#    #+#             */
/*   Updated: 2026/03/18 20:55:56 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonction cruciale : Vérifie si la pile est déjà parfaitement triée
// Retourne 1 si triée, 0 sinon.
static int  is_sorted(t_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

// Le chef d'orchestre du programme
int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;

    // 1. Quitte silencieusement si pas d'argument ou argument vide
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (0);
        
    stack_a = NULL;
    stack_b = NULL;
    
    // 2. Parsing sécurisé (gère les arguments multiples et les quotes)
    parse_arguments(&stack_a, argc, argv);
    
    // 3. Optimisation : On ne déclenche le tri que si nécessaire
    if (!is_sorted(stack_a))
    {
        // Ton algorithme analyse et choisit la meilleure méthode
        sort_adaptive(&stack_a, &stack_b);
    }
    
    // 4. Nettoyage chirurgical de la mémoire
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}