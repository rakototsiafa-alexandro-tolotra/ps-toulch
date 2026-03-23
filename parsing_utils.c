/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:16 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/23 18:26:26 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Vérifie si la chaîne ne contient que des chiffres (et gère les signes)
int is_numeric(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i]) // Interdit les "+" ou "-" isolés
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i])) // ft_isdigit vient de ta libft
            return (0);
        i++;
    }
    return (1);
}

// Convertit en long pour vérifier les overflows d'entiers
long ft_atol(const char *str)
{
    long    res;
    int     sign;
    int     i;

    res = 0;
    sign = 1;
    i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

// Parcours la pile pour vérifier s'il y a un doublon
int check_duplicate(t_node *a, int n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->value == n)
            return (1);
        a = a->next;
    }
    return (0);
}
