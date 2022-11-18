/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:11:32 by wcista            #+#    #+#             */
/*   Updated: 2022/11/11 19:34:45 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	error_return(t_stack *L)
{
	freelist(L);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	checks(t_stack *L, int n)
{
	if (check_duplicate_numbers(L) == -1)
		error_return(L);
	if (check_sorted(L) == -1 && n)
	{
		freelist(L);
		exit(EXIT_SUCCESS);
	}
}

void	check_numbers(const char *str, int i, t_stack *L)
{
	if (!*str)
		error_return(L);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_return(L);
		i++;
	}
}

int	check_duplicate_numbers(t_stack *L)
{
	t_stack	*tmp0;
	t_stack	*tmp1;

	tmp0 = L;
	while (tmp0)
	{
		tmp1 = tmp0->next;
		while (tmp1)
		{
			if (tmp0->value == tmp1->value)
				return (-1);
			tmp1 = tmp1->next;
		}
		tmp0 = tmp0->next;
	}
	return (0);
}

int	check_sorted(t_stack *L)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = L;
	while (tmp)
	{
		if (i != tmp->index)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
