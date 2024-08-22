/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:29:40 by wacista           #+#    #+#             */
/*   Updated: 2024/08/22 09:02:01 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_args(t_stack **L, int ac, char *av[])
{
	int	i;
	int	res;

	i = 1;
	while (i < ac)
	{
		res = ft_atoi(av[i], *L);
		*L = addat(*L, res, (i - 1));
		i++;
	}
}

void	set_index(t_stack *L)
{
	int		i;
	t_stack	*curr;
	t_stack	*comp;

	curr = L;
	while (curr)
	{
		comp = L;
		i = 1;
		while (comp)
		{
			if (curr->value > comp->value)
				i++;
			comp = comp->next;
		}
		curr->index = i;
		curr = curr->next;
	}
}
