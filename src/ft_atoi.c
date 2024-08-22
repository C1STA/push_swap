/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:57:17 by wacista           #+#    #+#             */
/*   Updated: 2024/08/22 09:00:02 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
