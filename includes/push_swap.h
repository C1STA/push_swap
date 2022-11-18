/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:45:50 by wcista            #+#    #+#             */
/*   Updated: 2022/11/11 19:35:26 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

void	sa(t_stack **A, int n);
void	sb(t_stack **B, int n);
void	ss(t_stack **A, t_stack **B, int n);
void	ra(t_stack **A, int n);
void	rb(t_stack **B, int n);
void	rr(t_stack **A, t_stack **B, int n);
void	rra(t_stack **A, int n);
void	rrb(t_stack **B, int n);
void	rrr(t_stack **A, t_stack **B, int n);
void	pa(t_stack **A, t_stack **B, int n);
void	pb(t_stack **A, t_stack **B, int n);

void	sort_ra(t_stack **A, int *cost);
void	sort_rb(t_stack **B, int *cost);
void	sort_rr(t_stack **A, t_stack **B, int *cost_a, int *cost_b);
void	sort_rrr(t_stack **A, t_stack **B, int *cost_a, int *cost_b);

int		ft_atoi(const char *str, t_stack *L);
int		check_duplicate_numbers(t_stack *L);
int		check_sorted(t_stack *L);
int		lenlist(t_stack *L);

int		find_lowest_cost(t_stack *B);
int		max_index(t_stack *L);
int		position_of_min_index(t_stack *L);
void	init_args(t_stack **A, int ac, char **av);
void	last_sort(t_stack **A);
void	sort_all(t_stack **A);
void	sort_it(t_stack **A, t_stack **B, int index);
void	sorting_of_three(t_stack **A, int max_index);
void	send_to_b(t_stack **A, t_stack **B);
void	set_position(t_stack *A, t_stack *B);
void	set_target(t_stack *A, t_stack *B);
void	calcul_the_cost(t_stack *A, t_stack *B);
void	set_index(t_stack *L);
void	push_swap(t_stack **A);
void	checks(t_stack *L, int n);
void	error_return(t_stack *L);
void	check_numbers(const char *str, int i, t_stack *L);

/*************BONUS********************/

void	operation_parsing(t_stack **A, t_stack **B, char *str);
void	operation_parsing2(t_stack **A, t_stack **B, char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif