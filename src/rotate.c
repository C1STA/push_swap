/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:40:25 by wacista           #+#    #+#             */
/*   Updated: 2024/08/27 21:20:15 by wacista          ###   ########.fr       */
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
		printf("ra\n");
}

void	rb(t_stack **B)
{
	if (rotate(B))
		printf("rb\n");
}

void	rr(t_stack **A, t_stack **B)
{
	bool	ra;
	bool	rb;

	ra = rotate(A);
	rb = rotate(B);
	if (ra && rb)
		ft_printf("rr\n");
	else if (ra)
		ft_printf("ra\n");
	else if (rb)
		ft_printf("rb\n");
}
