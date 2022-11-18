/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 01:05:51 by wcista            #+#    #+#             */
/*   Updated: 2022/11/10 17:38:01 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_atoi(const char *str, t_stack *L)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' && str[i + 1])
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+' && str[i + 1])
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (((result * sign) < INT_MIN) || ((result * sign) > INT_MAX))
		error_return(L);
	check_numbers(str, i, L);
	return ((int)result * sign);
}
