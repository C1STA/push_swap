/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:18:35 by wacista           #+#    #+#             */
/*   Updated: 2024/08/27 16:58:42 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int ac, char *av[])
{
	t_stack	*l;
	t_stack	*b;
	char	**av1;

	l = NULL;
	b = NULL;

	int i = 0;
	av1 = (char **)malloc((ac + 1) * sizeof(char *));
	while (i < ac)
	{
		av1[i] = (char *)malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		if (!i)
		{
			for (int k = 0; av[i][k]; k++)
				av1[i][k] = av[i][k];
		}
		else
		{
			for (int j = 0; av[i][j]; j++)
			{
				av1[i][j] = av[i][j] +  3;
			}
		}
		av1[i][ft_strlen(av[i])] = '\0';
		i++;
	}
	av1[i] = NULL;
	init_args(&l, ac, av);
	init_args(&b, ac, av1);
	set_index(l);
	set_index(b);
	//checks(l, 1);
	print_list(l);
	printf("\n");
	print_list(b);
	pb(&l, &b);
	printf("\n----------------\n");
	print_list(l);
	printf("\n");
	print_list(b);
	for (int i = 0; i < ac; i++)
		free(av1[i]);
	free(av1);
	freelist(l);
	freelist(b);
	return (0);
}
