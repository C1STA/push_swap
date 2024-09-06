/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:03:24 by wacista           #+#    #+#             */
/*   Updated: 2024/09/06 16:05:07 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_cost_value(int n)
{
	if (n > 0)
		return (n - 1);
	if (n < 0)
		return (n + 1);
	return (n);
}

static t_stack	*find_cheapest_cost(t_stack *B)
{
	int		cheapest;
	t_stack	*b;

	cheapest = INT_MAX;
	while (B)
	{
		if (B->final_cost < cheapest)
		{
			cheapest = B->final_cost;
			b = B;
		}
		B = B->next;
	}
	return (b);
}

void	exec(t_stack **A, t_stack **B)
{
	t_stack	*b;

	b = find_cheapest_cost(*B);
	while (b->cost_a || b->cost_b)
	{
		if (b->cost_a > 0 && b->cost_b > 0)
			rr(A, B, 1);
		else if (b->cost_a < 0 && b->cost_b < 0)
			rrr(A, B, 1);
		else if (b->cost_a > 0)
			ra(A, 1);
		if (b->cost_b > 0 && (!b->cost_a || b->cost_a < 0))
			rb(B, 1);
		if (b->cost_a < 0 && (!b->cost_b || b->cost_b > 0))
			rra(A, 1);
		if (b->cost_b < 0 && (!b->cost_a || b->cost_a > 0))
			rrb(B, 1);
		b->cost_a = set_cost_value(b->cost_a);
		b->cost_b = set_cost_value(b->cost_b);
	}
	pa(A, B, 1);
}
