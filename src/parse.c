/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:09:15 by wacista           #+#    #+#             */
/*   Updated: 2024/09/05 18:06:51 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_return(t_stack *L)
{
	freelist(L);
	write(2, "Error\n", 6);
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

int	ft_atoi(const char *s, t_stack *L)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (!*s)
		error_return(L);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if ((*s == '-' || *s == '+') && *(s + 1))
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - '0';
		s++;
	}
	if ((res * sign) < INT_MIN || (res * sign) > INT_MAX || *s)
		error_return(L);
	return ((int)res * sign);
}
