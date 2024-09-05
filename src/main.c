/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:18:35 by wacista           #+#    #+#             */
/*   Updated: 2024/09/05 18:36:42 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **L)
{
	int	len;

	len = lenlist(*L);
	if (len < 3)
		sa(L);
	else if (len > 3)
		big_sort(L);
	else if (len == 3)
		three_sort(L, len);
}

int	main(int ac, char *av[])
{
	t_stack	*a;

	a = NULL;
	init_args(&a, ac, av);
	set_index(a);
	checks(a, 1);
	push_swap(&a);
	freelist(a);
	return (0);
}
