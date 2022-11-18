/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:20:13 by wcista            #+#    #+#             */
/*   Updated: 2022/11/07 01:42:22 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	set_target(t_stack *A, t_stack *B)
{
	t_stack	*a;
	int		index_max;
	int		target_index;

	index_max = max_index(A);
	while (B)
	{
		a = A;
		target_index = INT_MAX;
		while (a)
		{
			if (B->index > index_max)
			{
				B->target_pos = position_of_min_index(A);
				break ;
			}
			if (a->index > B->index && a->index < target_index)
			{
					target_index = a->index;
					B->target_pos = a->pos;
			}
			a = a->next;
		}
		B = B->next;
	}
}

void	set_position(t_stack *A, t_stack *B)
{
	int	size;
	int	pos;

	pos = 0;
	size = lenlist(A);
	while (pos < size)
	{
		A->pos = pos;
		A = A->next;
		pos++;
	}
	pos = 0;
	size = lenlist(B);
	while (pos < size)
	{
		B->pos = pos;
		B = B->next;
		pos++;
	}
}
