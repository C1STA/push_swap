/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:08:44 by wacista           #+#    #+#             */
/*   Updated: 2024/09/06 16:07:39 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **L, int max_index)
{
	if ((*L)->index == max_index)
		ra(L, 1);
	if ((*L)->next->index == max_index)
		rra(L, 1);
	if ((*L)->index > (*L)->next->index)
		sa(L, 1);
}

static int	get_min_index_pos(t_stack *L)
{
	int	index;
	int	size;
	int	median;

	index = 0;
	size = lenlist(L);
	median = size / 2;
	if (size % 2)
		median++;
	while (L->index != 1)
	{
		index++;
		L = L->next;
	}
	if (index > median)
		return (-(size - index));
	return (index);
}

static void	last_sort(t_stack **A)
{
	int	index;

	index = get_min_index_pos(*A);
	while (index)
	{
		if (index < 0)
		{
			rra(A, 1);
			index++;
		}
		else if (index > 0)
		{
			ra(A, 1);
			index--;
		}
	}
}

void	big_sort(t_stack **A)
{
	t_stack	*b;

	b = NULL;
	send_to_b(A, &b);
	while (b)
	{
		set_pos(A);
		set_pos(&b);
		set_target(*A, b);
		set_cost(*A, b);
		exec(A, &b);
	}
	last_sort(A);
}
