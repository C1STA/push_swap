/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_presort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:42:54 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 12:47:06 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	even_or_odd_to_b(t_stack **A, t_stack **B, int size)
{
	int	i;

	i = 0;
	if ((size % 2) == 0)
	{
		while (i < (size / 2) - 3)
		{
			pb(A, B, 1);
		i++;
		}
	}
	else
	{
		while (i <= (size / 2) - 3)
		{
			pb(A, B, 1);
			i++;
		}
	}
}

void	send_to_b(t_stack **A, t_stack **B)
{
	int	i;
	int	size;

	i = 0;
	size = lenlist(*A);
	while (i < size)
	{
		if ((*A)->index <= size / 2 && lenlist(*A) > 3)
			pb(A, B, 1);
		else if (lenlist(*A) > 3)
			ra(A, 1);
		i++;
	}
	even_or_odd_to_b(A, B, size);
	sorting_of_three(A, max_index(*A));
}
