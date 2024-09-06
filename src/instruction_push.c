/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:00:08 by wacista           #+#    #+#             */
/*   Updated: 2024/09/06 16:01:05 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **A, t_stack **B, bool n)
{
	t_stack	*tmp;

	if (!B || !(*B))
		return ;
	tmp = *B;
	*B = (*B)->next;
	tmp->next = *A;
	*A = tmp;
	if (n)
		write(1, "pa\n", 3);
}

void	pb(t_stack **A, t_stack **B, bool n)
{
	t_stack	*tmp;

	if (!A || !(*A))
		return ;
	tmp = *A;
	*A = (*A)->next;
	tmp->next = *B;
	*B = tmp;
	if (n)
		write(1, "pb\n", 3);
}
