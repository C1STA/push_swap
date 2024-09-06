/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:40:25 by wacista           #+#    #+#             */
/*   Updated: 2024/09/06 16:02:04 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rotate(t_stack **L)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!L || !*L || !(*L)->next)
		return (false);
	tmp = (*L)->next;
	head = tmp;
	(*L)->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *L;
	*L = head;
	return (true);
}

void	ra(t_stack **A, bool n)
{
	if (rotate(A) && n)
		write(1, "ra\n", 3);
}

void	rb(t_stack **B, bool n)
{
	if (rotate(B) && n)
		write(1, "rb\n", 3);
}

void	rr(t_stack **A, t_stack **B, bool n)
{
	bool	ra;
	bool	rb;

	ra = rotate(A);
	rb = rotate(B);
	if (ra && rb && n)
		write(1, "rr\n", 3);
	else if (ra && n)
		write(1, "ra\n", 3);
	else if (rb && n)
		write(1, "rb\n", 3);
}
