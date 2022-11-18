/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:02:37 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 18:25:26 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static t_stack	*createcell(int data)
{
	t_stack	*cell;

	cell = malloc(sizeof(t_stack));
	if (!cell)
		return (NULL);
	cell->value = data;
	cell->next = NULL;
	return (cell);
}

t_stack	*addat(t_stack *L, int data, int pos)
{
	t_stack	*precedent;
	t_stack	*current;
	t_stack	*cell;
	int		i;

	precedent = L;
	current = L;
	cell = createcell(data);
	if (!(L))
		return (cell);
	if (pos == 0)
	{
		cell->next = L;
		return (cell);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		precedent = current;
		current = current ->next;
	}
	precedent->next = cell;
	cell->next = current;
	return (L);
}

t_stack	*freelist(t_stack *L)
{
	t_stack	*tmp;

	tmp = NULL;
	while (L)
	{
		tmp = L->next;
		free(L);
		L = tmp;
	}
	return (L);
}

int	lenlist(t_stack *L)
{
	int	len;

	len = 0;
	while (L)
	{
		len++;
		L = L->next;
	}
	return (len);
}
