/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:50:45 by wcista            #+#    #+#             */
/*   Updated: 2022/11/04 18:05:47 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

void	calcul_the_cost(t_stack *A, t_stack *B)
{
	t_stack	*a;
	int		size_b;

	size_b = lenlist(B);
	while (B)
	{
		a = A;
		while (a)
		{
			if (a->pos == B->target_pos)
			{
				if (lenlist(A) / 2 < a->pos)
					B->cost_a = (lenlist(A) - a->pos) * (-1);
				if (lenlist(A) / 2 >= a->pos)
					B->cost_a = a->pos;
			}
			a = a->next;
		}
		if (size_b / 2 < B->pos)
			B->cost_b = (size_b - B->pos) * (-1);
		if (size_b / 2 >= B->pos)
			B->cost_b = B->pos;
		B->final_cost = abs(B->cost_a) + abs(B->cost_b);
		B = B->next;
	}
}

int	find_lowest_cost(t_stack *B)
{
	t_stack	*tmp1;
	int		lowest;
	int		index;

	tmp1 = B;
	lowest = INT_MAX;
	while (tmp1)
	{
		if (tmp1->final_cost <= lowest)
		{
			lowest = tmp1->final_cost;
			index = tmp1->index;
		}
		tmp1 = tmp1->next;
	}
	return (index);
}
