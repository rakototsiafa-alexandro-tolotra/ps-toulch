/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herasoan <herasoan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:27 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/18 10:58:09 by herasoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_exit(t_list **a, char **matrix, int is_split)
{
	if (is_split)
		error_exit(a, matrix);
	else
		error_exit(a, NULL);
}
// Traite un tableau de chaînes (issu de argv ou de ft_split)
static void process_strings(t_list **a, char **matrix, int is_split)
{
	int     i;
	long    nb;

	i = 0;
	while (matrix[i])
	{
		if (!is_numeric(matrix[i]))
			check_exit(a, matrix, is_split);
		nb = ft_atol(matrix[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			check_exit(a, matrix, is_split);
		if (check_duplicate(*a, (int)nb))
			check_exit(a, matrix, is_split);
		append_node(a, (int)nb);
		i++;
	}
}

// Fonction principale appelée par le main
void parse_arguments(t_list **a, int argc, char **argv)
{
	char    **matrix;
	int     i;

	i = 1; // On commence à 1 pour ignorer le nom du programme (argv[0])
	while (i < argc)
	{
		// Gère le cas où les arguments sont passés entre guillemets ("1 2 3")
		// ou pour traiter des arguments multiples normaux un par un.
		matrix = ft_split(argv[i], ' ');
		if (!matrix || !matrix[0])
			error_exit(a, matrix);

		// On envoie à la fonction de traitement. "1" indique que c'est un tableau ft_split à free en cas d'erreur.
		process_strings(a, matrix, 1);

		// On libère le tableau ft_split une fois les nombres transférés dans la pile
		free_matrix(matrix);
		i++;
	}
}
