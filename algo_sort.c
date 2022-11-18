/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:45:20 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 12:46:29 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sorting_of_three(t_stack **A, int max_index)
{
	t_stack	*tmp;

	tmp = *A;
	if (tmp->index == max_index)
		ra(&tmp, 1);
	if (tmp->next->index == max_index)
		rra(&tmp, 1);
	if (tmp->index > tmp->next->index)
		sa(&tmp, 1);
	*A = tmp;
}

void	last_sort(t_stack **A)
{
	t_stack	*a;
	int		size;
	int		i;

	a = *A;
	size = lenlist(a);
	while (a)
	{
		if (a->pos == position_of_min_index(*A))
		{
			if (size / 2 < a->pos)
			{
				i = size - a->pos;
				while (i--)
					rra(A, 1);
			}
			if (size / 2 >= a->pos)
			{
				i = a->pos;
				while (i--)
					ra(A, 1);
			}
		}
		a = a->next;
	}
}

void	sort_it(t_stack **A, t_stack **B, int index)
{
	t_stack	*b;
	int		cost_a;
	int		cost_b;

	b = *B;
	while (b)
	{
		if (b->index == index)
		{
			cost_a = b->cost_a;
			cost_b = b->cost_b;
			if (cost_a < 0 && cost_b < 0)
				sort_rrr(A, B, &cost_a, &cost_b);
			else if (cost_a > 0 && cost_b > 0)
				sort_rr(A, B, &cost_a, &cost_b);
			sort_ra(A, &cost_a);
			sort_rb(B, &cost_b);
			pa(A, B, 1);
		}
		b = b->next;
	}
}

void	sort_all(t_stack **A)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		size;

	a = *A;
	b = NULL;
	send_to_b(&a, &b);
	size = lenlist(b);
	i = 0;
	while (i < size)
	{
		set_position(a, b);
		set_target(a, b);
		calcul_the_cost(a, b);
		sort_it(&a, &b, find_lowest_cost(b));
		i++;
	}
	set_position(a, b);
	last_sort(&a);
	*A = a;
}
