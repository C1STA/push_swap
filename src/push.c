/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:00:08 by wacista           #+#    #+#             */
/*   Updated: 2024/08/27 17:02:50 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **A, t_stack **B)
{
	t_stack	*tmp;

	if (!B || !(*B))
		return ;
	tmp = *B;
	*B = (*B)->next;
	tmp->next = *A;
	*A = tmp;
	ft_printf("pa\n");
}

void	pb(t_stack **A, t_stack **B)
{
	t_stack	*tmp;

	if (!A || !(*A))
		return ;
	tmp = *A;
	*A = (*A)->next;
	tmp->next = *B;
	*B = tmp;
	ft_printf("pb\n");
}
