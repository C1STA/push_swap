/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:07:56 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 12:40:15 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap(t_stack **L)
{
	t_stack	*tmp0;
	t_stack	*tmp1;

	tmp0 = *L;
	if (tmp0 == NULL || tmp0->next == NULL)
		return ;
	tmp1 = tmp0->next;
	tmp0->next = tmp1->next;
	tmp1->next = tmp0;
	*L = tmp1;
}

void	sa(t_stack **A, int n)
{
	swap(A);
	if (n)
		write(1, "sa\n", 3);
}

void	sb(t_stack **B, int n)
{
	swap(B);
	if (n)
		write(1, "sb\n", 3);
}

void	ss(t_stack **A, t_stack **B, int n)
{
	swap(A);
	swap(B);
	if (n)
		write(1, "ss\n", 3);
}
