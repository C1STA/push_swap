/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rev_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:23:05 by wacista           #+#    #+#             */
/*   Updated: 2024/09/05 18:10:53 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rev_rotate(t_stack **L)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!L || !*L || !(*L)->next)
		return (false);
	last = *L;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *L;
	*L = last;
	return (true);
}

void	rra(t_stack **A)
{
	if (rev_rotate(A))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **B)
{
	if (rev_rotate(B))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **A, t_stack **B)
{
	bool	rra;
	bool	rrb;

	rra = rev_rotate(A);
	rrb = rev_rotate(B);
	if (rra && rrb)
		write(1, "rrr\n", 4);
	else if (rra)
		write(1, "rra\n", 4);
	else if (rrb)
		write(1, "rrb\n", 4);
}
