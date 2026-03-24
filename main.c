/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:55:56 by arakotot          #+#    #+#             */
/*   Updated: 2026/03/23 19:00:00 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node *stack)
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

static int	is_empty_input(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argc == 2 && argv[1][0] == '\0')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (is_empty_input(argc, argv))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parse_arguments(&stack_a, argc, argv);
	if (!stack_a)
		return (0);
	if (!is_sorted(stack_a))
		sort_adaptive(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
