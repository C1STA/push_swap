/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:18:35 by wacista           #+#    #+#             */
/*   Updated: 2024/08/26 20:58:49 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*l;

	l = NULL;
	init_args(&l, ac, av);
	set_index(l);
	checks(l, 1);
	freelist(l);
	return (0);
}
