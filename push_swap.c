/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:45:02 by wcista            #+#    #+#             */
/*   Updated: 2022/11/11 19:35:48 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_swap(t_stack **A)
{
	t_stack	*a;
	int		len;

	a = *A;
	len = lenlist(a);
	if (len > 3)
		sort_all(&a);
	if (len == 2)
		sa(&a, 1);
	if (len == 3)
		sorting_of_three(&a, len);
	*A = a;
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
