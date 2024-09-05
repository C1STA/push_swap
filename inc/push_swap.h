/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:14:02 by wacista           #+#    #+#             */
/*   Updated: 2024/09/05 18:34:56 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

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

void	sa(t_stack **A);
void	sb(t_stack **B);
void	ss(t_stack **A, t_stack **B);

void	pa(t_stack **A, t_stack **B);
void	pb(t_stack **A, t_stack **B);

void	ra(t_stack **A);
void	rb(t_stack **B);
void	rr(t_stack **A, t_stack **B);

void	rra(t_stack **A);
void	rrb(t_stack **B);
void	rrr(t_stack **A, t_stack **B);

void	three_sort(t_stack **L, int max_index);
void	big_sort(t_stack **A);

void	send_to_b(t_stack **A, t_stack **B);

void	set_pos(t_stack **L);
void	set_target(t_stack *A, t_stack *B);
int		find_max_index(t_stack *L);

void	set_cost(t_stack *A, t_stack *B);

void	exec(t_stack **A, t_stack **B);

#endif