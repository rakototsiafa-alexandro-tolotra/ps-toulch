/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:44 by herasoan          #+#    #+#             */
/*   Updated: 2026/03/23 22:47:28 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

static void	sort_small(t_node **a, int size)
{
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (size == 3)
		sort_three(a);
}

static void	rotate_min_to_top(t_node **a, int size)
{
	int	min_pos;

	min_pos = get_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
}

static int	find_insert_pos(t_node *a, int val, int size_a)
{
	t_node	*tmp;
	int		pos;

	tmp = a;
	pos = 0;
	while (tmp)
	{
		if (tmp->value > val)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (size_a);
}

static void	insert_from_b(t_node **a, t_node **b)
{
	int	best_pos;
	int	size_a;
	int	steps;

	while (*b)
	{
		size_a = get_stack_size(*a);
		best_pos = find_insert_pos(*a, (*b)->value, size_a);
		if (best_pos <= size_a / 2)
		{
			while (best_pos-- > 0)
				ra(a);
		}
		else
		{
			steps = size_a - best_pos;
			while (steps-- > 0)
				rra(a);
		}
		pa(b, a);
	}
}

void	sort_simple(t_node **a, t_node **b)
{
	int	size;

	size = get_stack_size(*a);
	if (size <= 3)
	{
		sort_small(a, size);
		return ;
	}
	while (size > 3)
	{
		rotate_min_to_top(a, size);
		pb(a, b);
		size--;
	}
	sort_three(a);
	insert_from_b(a, b);
}