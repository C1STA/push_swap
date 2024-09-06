/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wacista <wacista@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:36:37 by wacista           #+#    #+#             */
/*   Updated: 2024/09/06 16:16:47 by wacista          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*join_buffer(char *s1, char *s2);
int		is_newline(char *s);
char	*cpy_newline(char *s);
char	*new_buffer(char *s);
void	free_buffer(char *buffer);
size_t	ft_strlen(const char *s);

#endif