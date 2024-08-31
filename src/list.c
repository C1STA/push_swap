/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:19:47 by wacista           #+#    #+#             */
/*   Updated: 2024/08/31 17:20:53 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		i;
	t_stack	*prec;
	t_stack	*curr;
	t_stack	*cell;

	prec = L;
	curr = L;
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
		prec = curr;
		curr = curr->next;
		i++;
	}
	prec->next = cell;
	cell->next = curr;
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
		L = L->next;
		len++;
	}
	return (len);
}

void	print_list(t_stack *L, char c)
{
	if (!L)
		return ;
	printf("List: %c\n", c);
	while (L)
	{
		printf("%c->value: %d - %c->index: %d - %c->pos: %d - %c->tar\
get_pos: %d - %c->cost_a: %d - %c->cost_b: %d\n", c, L->value, c, L->index, c, L->pos, c, L->target_pos, c, L->cost_a, c, L->cost_b);
		L = L->next;
	}
}
