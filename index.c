/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:12:40 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 14:37:42 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	index_initializer(t_stack *L)
{
	while (L)
	{
		L->index = 1;
		L = L->next;
	}
}

int	max_index(t_stack *L)
{
	t_stack	*tmp0;
	t_stack	*tmp1;
	int		index_max;

	tmp0 = L;
	index_max = tmp0->index;
	while (tmp0)
	{
		tmp1 = L;
		while (tmp1)
		{
			if (tmp1->index > index_max)
				index_max = tmp1->index;
			tmp1 = tmp1->next;
		}
		tmp0 = tmp0->next;
	}
	return (index_max);
}

int	position_of_min_index(t_stack *L)
{
	t_stack	*tmp;
	t_stack	*tmp1;
	int		index;

	tmp = L;
	tmp1 = L;
	index = tmp->index;
	while (tmp)
	{
		while (tmp1)
		{
			if (tmp1->index < index)
				index = tmp1->index;
			tmp1 = tmp1->next;
		}
		if (tmp->index == index)
			return (tmp->pos);
		tmp = tmp->next;
	}
	return (tmp->pos);
}

void	set_index(t_stack *L)
{
	t_stack	*tmp0;
	t_stack	*tmp1;
	int		i;

	index_initializer(L);
	tmp0 = L;
	while (tmp0)
	{
		tmp1 = L;
		i = 1;
		while (tmp1)
		{
			if (tmp0->value > tmp1->value)
			{
				tmp0->index = i + 1;
				i++;
			}
			tmp1 = tmp1->next;
		}
		tmp0 = tmp0->next;
	}
}

void	init_args(t_stack **A, int ac, char **av)
{
	int	i;
	int	res;

	i = 1;
	while (i < ac)
	{
		res = ft_atoi(av[i], *A);
		i--;
		*A = addat(*A, res, i);
		i += 2;
	}
}
