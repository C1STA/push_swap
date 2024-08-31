/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:56:39 by wacista           #+#    #+#             */
/*   Updated: 2024/08/31 22:35:25 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

static int	get_rrb_cost(t_stack *L, int pos)
{
	int	res;

	res = 0;
	while (pos != res)
	{
		L = L->next;
		res++;
	}
	return (res);
}

static int	get_cost_a(t_stack *A, int target, int median)
{
	int	res;

	res = 0;
	while (A->pos != target)
	{
		A = A->next;
		res++;
	}
	if (res > median)
		res = -lenlist(A);
	return (res);
}

void	set_cost(t_stack *A, t_stack *B)
{
	t_stack	*b;
	int		median_a;
	int		median_b;

	b = B;
	median_a = lenlist(A) / 2;
	median_b = lenlist(B) / 2;
	while (b)
	{
		b->cost_a = get_cost_a(A, b->target_pos, median_a);
		if (b->pos > median_b)
			b->cost_b = -lenlist(b);
		else
			b->cost_b = get_rrb_cost(B, b->pos);
		b->final_cost = abs_(b->cost_a) + abs_(b->cost_b);
		b = b->next;
	}
}
