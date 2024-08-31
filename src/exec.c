/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:03:24 by wacista           #+#    #+#             */
/*   Updated: 2024/08/31 22:46:54 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest_cost(t_stack *B)
{
	int	cheapest;
	int	pos;

	cheapest = INT_MAX;
	while (B)
	{
		if (B->final_cost < cheapest)
		{
			cheapest = B->final_cost;
			pos = B->pos;
		}
		B = B->next;
	}
	return(pos);
}

void	exec(t_stack **A, t_stack **B)
{
	int		pos;
	//t_stack	*a;
	t_stack	*b;

	//a = *A;
	b = *B;
	pos = find_cheapest_cost(*B);
	while (b->pos != pos)
		b = b->next;
	//while (a->pos != b->target_pos)
	//	a = a->next;
	if (b->cost_a < 0)
	{
		while (b->cost_a)
		{
			rra(A);
			b->cost_a++;
		}
	}
	if (b->cost_a > 0)
	{
		while (b->cost_a)
		{
			ra(A);
			b->cost_a--;
		}
	}


	if (b->cost_b < 0)
	{
		while (b->cost_b)
		{
			rrb(B);
			b->cost_b++;
		}
	}
	if (b->cost_b > 0)
	{
		while (b->cost_b)
		{
			rb(B);
			b->cost_b--;
		}
	}
	pa(A, B);
}
