/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:02:55 by wcista            #+#    #+#             */
/*   Updated: 2022/11/11 19:35:06 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	operation_parsing(t_stack **A, t_stack **B, char *str)
{
	size_t	len;

	len = ft_strlen((const char *)str);
	if (!ft_strncmp(str, "sa\n", len))
		sa(A, 0);
	else if (!ft_strncmp(str, "sb\n", len))
		sb(B, 0);
	else if (!ft_strncmp(str, "ss\n", len))
		ss(A, B, 0);
	else if (!ft_strncmp(str, "pa\n", len))
		pa(A, B, 0);
	else if (!ft_strncmp(str, "pb\n", len))
		pb(A, B, 0);
	else
		operation_parsing2(A, B, str);
}

void	operation_parsing2(t_stack **A, t_stack **B, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (!ft_strncmp(str, "ra\n", len))
		ra(A, 0);
	else if (!ft_strncmp(str, "rb\n", len))
		rb(B, 0);
	else if (!ft_strncmp(str, "rr\n", len))
		rr(A, B, 0);
	else if (!ft_strncmp(str, "rra\n", len))
		rra(A, 0);
	else if (!ft_strncmp(str, "rrb\n", len))
		rrb(B, 0);
	else if (!ft_strncmp(str, "rrr\n", len))
		rrr(A, B, 0);
	else
	{
		freelist(*B);
		free(str);
		error_return(*A);
	}
}

void	is_ok_or_ko(t_stack **A, t_stack **B)
{
	if (check_sorted(*A) && !(*B))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	init_args(&a, ac, av);
	set_index(a);
	checks(a, 0);
	str = get_next_line(0);
	while (str)
	{
		operation_parsing(&a, &b, str);
		free(str);
		str = get_next_line(0);
	}
	is_ok_or_ko(&a, &b);
	freelist(a);
	freelist(b);
	return (0);
}
