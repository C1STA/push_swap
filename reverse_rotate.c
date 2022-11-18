/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:09:37 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 12:42:14 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	reverse_r(t_stack **L)
{
	t_stack	*tmp0;
	t_stack	*tmp1;

	tmp0 = *L;
	if (tmp0 == NULL || tmp0->next == NULL)
		return ;
	while (tmp0)
	{
		if (tmp0->next->next == NULL)
		{
			tmp1 = tmp0->next;
			tmp0->next = NULL;
			break ;
		}
		tmp0 = tmp0->next;
	}
	tmp0 = *L;
	tmp1->next = tmp0;
	*L = tmp1;
}

void	rra(t_stack **A, int n)
{
	reverse_r(A);
	if (n)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **B, int n)
{
	reverse_r(B);
	if (n)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **A, t_stack **B, int n)
{
	reverse_r(A);
	reverse_r(B);
	if (n)
		write(1, "rrr\n", 4);
}
