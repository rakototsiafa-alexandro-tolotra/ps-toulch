/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:49:07 by arakotot          #+#    #+#             */
/*   Updated: 2026/03/23 19:00:00 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	radix_pass(t_node **a, t_node **b, int size, int bit)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while (*b)
		pa(b, a);
}

void	sort_complex(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	i;

	index_stack(*a);
	size = get_stack_size(*a);
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		radix_pass(a, b, size, i);
		i++;
	}
}