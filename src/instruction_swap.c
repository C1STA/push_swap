/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:42:29 by wacista           #+#    #+#             */
/*   Updated: 2024/08/31 21:30:00 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_stack **L)
{
	t_stack	*tmp;

	if (!L || !*L || !(*L)->next)
		return (false);
	tmp = (*L)->next;
	(*L)->next = tmp->next;
	tmp->next = *L;
	*L = tmp;
	return (true);
}

void	sa(t_stack **A)
{
	if (swap(A))
		ft_printf("sa\n");
}

void	sb(t_stack **B)
{
	if (swap(B))
		ft_printf("sb\n");
}

void	ss(t_stack **A, t_stack **B)
{
	bool	sa;
	bool	sb;

	sa = swap(A);
	sb = swap(B);
	if (sa && sb)
		ft_printf("ss\n");
	else if (sa)
		ft_printf("sa\n");
	else if (sb)
		ft_printf("sb\n");
}
