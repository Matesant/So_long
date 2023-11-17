/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:03:38 by matesant          #+#    #+#             */
/*   Updated: 2023/11/16 16:39:59 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	g_ft_strlen(const char *str);
char	*g_ft_strjoin(const char *dest, char *str);
char	*g_ft_strchr(const char *str, int c);
char	*g_ft_strdup(const char *str);
size_t	g_ft_strlcpy(char *dest, const char *str, size_t n);

#endif