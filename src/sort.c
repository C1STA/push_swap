/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:08:44 by wacista           #+#    #+#             */
/*   Updated: 2024/08/30 21:26:36 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **L, int max_index)
{
	if ((*L)->index == max_index)
		ra(L);
	if ((*L)->next->index == max_index)
		rra(L);
	if ((*L)->index > (*L)->next->index)
		sa(L);
}

void	big_sort(t_stack **A)
{
	t_stack	*b;

	b = NULL;
	send_to_b(A, &b);
	//while (b)
	//{
		set_pos(A);
		set_pos(&b);
		set_target(*A, b);
	//}
	print_list(*A, 'A');
	print_list(b, 'B');
}
