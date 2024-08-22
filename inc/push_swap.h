/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:14:02 by wacista           #+#    #+#             */
/*   Updated: 2024/08/22 11:36:10 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				final_cost;
	struct s_stack	*next;
}	t_stack;

t_stack	*addat(t_stack *L, int data, int pos);
t_stack	*freelist(t_stack *L);
int		lenlist(t_stack *L);

int		ft_atoi(const char *s, t_stack *L);

void	checks(t_stack *L, int n);
void	error_return(t_stack *L);

void	init_args(t_stack **L, int ac, char *av[]);
void	set_index(t_stack *L);

#endif