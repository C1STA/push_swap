/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:55:57 by wacista           #+#    #+#             */
/*   Updated: 2024/09/06 16:38:08 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "get_next_line.h"

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
bool	is_sorted(t_stack *L);

void	init_args(t_stack **L, int ac, char *av[]);
void	set_index(t_stack *L);

void	sa(t_stack **A, bool n);
void	sb(t_stack **B, bool n);
void	ss(t_stack **A, t_stack **B, bool n);

void	pa(t_stack **A, t_stack **B, bool n);
void	pb(t_stack **A, t_stack **B, bool n);

void	ra(t_stack **A, bool n);
void	rb(t_stack **B, bool n);
void	rr(t_stack **A, t_stack **B, bool n);

void	rra(t_stack **A, bool n);
void	rrb(t_stack **B, bool n);
void	rrr(t_stack **A, t_stack **B, bool n);

#endif