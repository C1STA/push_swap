/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:40:25 by wacista           #+#    #+#             */
/*   Updated: 2024/09/05 18:08:39 by wacista          ###   ########.fr       */
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

void	ra(t_stack **A)
{
	if (rotate(A))
		write(1, "ra\n", 3);
}

void	rb(t_stack **B)
{
	if (rotate(B))
		write(1, "rb\n", 3);
}

void	rr(t_stack **A, t_stack **B)
{
	bool	ra;
	bool	rb;

	ra = rotate(A);
	rb = rotate(B);
	if (ra && rb)
		write(1, "rr\n", 3);
	else if (ra)
		write(1, "ra\n", 3);
	else if (rb)
		write(1, "rb\n", 3);
}
