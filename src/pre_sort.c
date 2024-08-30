/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:30:47 by wacista           #+#    #+#             */
/*   Updated: 2024/08/30 21:17:01 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_smaller_median(t_stack *A, int size)
{
	int	median;

	median = size / 2;
	if (size == 4)
		median = 1;
	while (A)
	{
		if (A->index <= median)
			return (false);
		A = A->next;
	}
	return (true);
}

static void	send_rest_to_b(t_stack **A, t_stack **B, int size, int median)
{
	int	i;

	if (size % 2)
		median++;
	i = 0;
	while (i < median - 3)
	{
		pb(A, B);
		i++;
	}
}

void	send_to_b(t_stack **A, t_stack **B)
{
	int	i;
	int	size;
	int	median;

	i = 0;
	size = lenlist(*A);
	median = size / 2;
	if (size == 4)
		median = 1;
	while (i < size)
	{
		if ((*A)->index <= median)
		{
			pb(A, B);
			if (is_smaller_median(*A, size))
				break ;
		}
		else
			ra(A);
		i++;
	}
	send_rest_to_b(A, B, size, median);
	three_sort(A, find_max_index(*A));
}
