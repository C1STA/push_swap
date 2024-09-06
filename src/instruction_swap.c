/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:42:29 by wacista           #+#    #+#             */
/*   Updated: 2024/09/06 15:59:21 by wacista          ###   ########.fr       */
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

void	sa(t_stack **A, bool n)
{
	if (swap(A) && n)
		write(1, "sa\n", 3);
}

void	sb(t_stack **B, bool n)
{
	if (swap(B) && n)
		write(1, "sb\n", 3);
}

void	ss(t_stack **A, t_stack **B, bool n)
{
	bool	sa;
	bool	sb;

	sa = swap(A);
	sb = swap(B);
	if (sa && sb && n)
		write(1, "ss\n", 3);
	else if (sa && n)
		write(1, "sa\n", 3);
	else if (sb && n)
		write(1, "sb\n", 3);
}
