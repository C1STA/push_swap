/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:08:44 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 12:41:42 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	rotate(t_stack **L)
{
	t_stack	*tmp0;
	t_stack	*tmp1;

	tmp0 = *L;
	tmp1 = *L;
	if (tmp0 == NULL || tmp0->next == NULL)
		return ;
	*L = tmp1->next;
	while (tmp0)
	{
		tmp0 = tmp0->next;
		if (tmp0->next == NULL)
		{
			tmp0->next = tmp1;
			tmp0->next->next = NULL;
			break ;
		}
	}
}

void	ra(t_stack **A, int n)
{
	rotate(A);
	if (n)
		write(1, "ra\n", 3);
}

void	rb(t_stack **B, int n)
{
	rotate(B);
	if (n)
		write(1, "rb\n", 3);
}

void	rr(t_stack **A, t_stack **B, int n)
{
	rotate(A);
	rotate(B);
	if (n)
		write(1, "rr\n", 3);
}
