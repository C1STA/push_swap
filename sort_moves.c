/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 05:42:12 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 12:44:19 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_ra(t_stack **A, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(A, 1);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(A, 1);
			(*cost)++;
		}
	}
}

void	sort_rb(t_stack **B, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(B, 1);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(B, 1);
			(*cost)++;
		}
	}
}

void	sort_rr(t_stack **A, t_stack **B, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(A, B, 1);
	}
}

void	sort_rrr(t_stack **A, t_stack **B, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(A, B, 1);
	}
}
