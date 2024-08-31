/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:13:24 by wacista           #+#    #+#             */
/*   Updated: 2024/08/31 23:34:28 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_stack **L)
{
	int		i;
	t_stack	*head;

	i = 0;
	if (!L || !*L)
		return ;
	head = *L;
	while (*L)
	{
		(*L)->pos = i++;
		*L = (*L)->next;
	}
	*L = head;
}

static int	position_of_min_index(t_stack *L)
{
	int	pos;
	long	min_index;

	min_index = LONG_MAX;
	while (L)
	{
		if (L->index < min_index)
		{
			min_index = L->index;
			pos = L->pos;
		}
		L = L->next;
	}
	return (pos);
}

static bool	is_bigger_index(t_stack *A, t_stack *B, int index_max)
{
	if (B->index > index_max)
	{
		B->target_pos = position_of_min_index(A);
		return (true);
	}
	return (false);
}

void	set_target(t_stack *A, t_stack *B)
{
	t_stack	*a;
	int		index_max;
	long	closer;

	index_max = find_max_index(A);
	while (B)
	{
		a = A;
		closer = LONG_MAX;
		while (a)
		{
			if (is_bigger_index(A, B, index_max))
				break ;
			if (a->index > B->index && closer > a->index - B->index)
			{
				closer = a->index - B->index;
				B->target_pos = a->pos;
				if (closer == 1)
					break ;
			}
			a = a->next;
		}
		B = B->next;
	}
}
