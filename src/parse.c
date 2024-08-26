/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:09:15 by wacista           #+#    #+#             */
/*   Updated: 2024/08/22 13:13:51 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_return(t_stack *L)
{
	freelist(L);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

static int	is_duplicate(t_stack *L)
{
	t_stack	*curr;
	t_stack	*comp;

	curr = L;
	while (curr)
	{
		comp = curr->next;
		while (comp)
		{
			if (curr->value == comp->value)
				return (1);
			comp = comp->next;
		}
		curr = curr->next;
	}
	return (0);
}

static int	is_sorted(t_stack *L)
{
	int		i;
	t_stack	*curr;

	i = 1;
	curr = L;
	while (curr)
	{
		if (curr->index != i)
			return (0);
		i++;
		curr = curr->next;
	}
	return (1);
}

void	checks(t_stack *L, int n)
{
	if (is_duplicate(L))
		error_return(L);
	if (is_sorted(L) && n)
	{
		freelist(L);
		exit(EXIT_SUCCESS);
	}
}
