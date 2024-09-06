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

static bool	operation_parsing(t_stack **A, t_stack **B, char *s, size_t len)
{
	if (!ft_strncmp(s, "sa\n", len))
		sa(A, 0);
	else if (!ft_strncmp(s, "sb\n", len))
		sb(B, 0);
	else if (!ft_strncmp(s, "ss\n", len))
		ss(A, B, 0);
	else if (!ft_strncmp(s, "ra\n", len))
		ra(A, 0);
	else if (!ft_strncmp(s, "rb\n", len))
		rb(B, 0);
	else if (!ft_strncmp(s, "rr\n", len))
		rr(A, B, 0);
	else if (!ft_strncmp(s, "rra\n", len))
		rra(A, 0);
	else if (!ft_strncmp(s, "rrb\n", len))
		rrb(B, 0);
	else if (!ft_strncmp(s, "rrr\n", len))
		rrr(A, B, 0);
	else if (!ft_strncmp(s, "pa\n", len))
		pa(A, B, 0);
	else if (!ft_strncmp(s, "pb\n", len))
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
	size_t	len;

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
		len = ft_strlen(s);
		operation_parsing(&a, &b, s, len);
		free(s);
		s = get_next_line(STDIN_FILENO);
	}
	is_ok_or_ko(a, b);
	freelist(a);
	freelist(b);
	return (0);
}
