/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:10:48 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 12:42:26 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	pa(t_stack **A, t_stack **B, int n)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *A;
	tmp_b = *B;
	if (tmp_b == NULL)
		return ;
	*B = tmp_b->next;
	tmp_b->next = tmp_a;
	*A = tmp_b;
	if (n)
		write(1, "pa\n", 3);
}

void	pb(t_stack **A, t_stack **B, int n)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *A;
	tmp_b = *B;
	if (tmp_a == NULL)
		return ;
	*A = tmp_a->next;
	tmp_a->next = tmp_b;
	*B = tmp_a;
	if (n)
		write(1, "pb\n", 3);
}
