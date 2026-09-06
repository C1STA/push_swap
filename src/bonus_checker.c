/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:15:16 by wacista           #+#    #+#             */
/*   Updated: 2024/09/06 17:48:31 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static bool	operation_parsing(t_stack **A, t_stack **B, char *s)
{
	if (!ft_strncmp(s, "sa\n", 4))
		sa(A, 0);
	else if (!ft_strncmp(s, "sb\n", 4))
		sb(B, 0);
	else if (!ft_strncmp(s, "ss\n", 4))
		ss(A, B, 0);
	else if (!ft_strncmp(s, "ra\n", 4))
		ra(A, 0);
	else if (!ft_strncmp(s, "rb\n", 4))
		rb(B, 0);
	else if (!ft_strncmp(s, "rr\n", 4))
		rr(A, B, 0);
	else if (!ft_strncmp(s, "rra\n", 5))
		rra(A, 0);
	else if (!ft_strncmp(s, "rrb\n", 5))
		rrb(B, 0);
	else if (!ft_strncmp(s, "rrr\n", 5))
		rrr(A, B, 0);
	else if (!ft_strncmp(s, "pa\n", 4))
		pa(A, B, 0);
	else if (!ft_strncmp(s, "pb\n", 4))
		pb(A, B, 0);
	else
		return (free(s), freelist(*B), error_return(*A), 1);
	return (0);
}

static void	is_ok_or_ko(t_stack *A, t_stack *B)
{
	if (is_sorted(A) && !B)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	*s;

	if (ac < 2)
		return (EXIT_FAILURE);
	a = NULL;
	b = NULL;
	init_args(&a, ac, av);
	set_index(a);
	checks(a, 0);
	s = get_next_line(STDIN_FILENO);
	while (s)
	{
		operation_parsing(&a, &b, s);
		free(s);
		s = get_next_line(STDIN_FILENO);
	}
	is_ok_or_ko(a, b);
	freelist(a);
	freelist(b);
	return (0);
}
