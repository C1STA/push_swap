/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:56:39 by wacista           #+#    #+#             */
/*   Updated: 2024/09/05 17:50:09 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_(int value)
{
	if (value < 0)
		return (-value);
	return (value);
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

static int	get_cost_b(t_stack *L, int pos)
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

void	set_cost(t_stack *A, t_stack *B)
{
	t_stack	*b;
	int		median_a;
	int		median_b;
	int		size_a;
	int		size_b;

	b = B;
	size_a = lenlist(A);
	median_a = size_a / 2;
	if (size_a % 2)
		median_a++;
	size_b = lenlist(B);
	median_b = size_b / 2;
	if (size_b % 2)
		median_b++;
	while (b)
	{
		b->cost_a = get_cost_a(A, b->target_pos, median_a);
		if (b->pos > median_b)
			b->cost_b = -lenlist(b);
		else
			b->cost_b = get_cost_b(B, b->pos);
		b->final_cost = abs_(b->cost_a) + abs_(b->cost_b);
		b = b->next;
	}
}
