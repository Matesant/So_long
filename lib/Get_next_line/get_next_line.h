/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:03:38 by matesant          #+#    #+#             */
/*   Updated: 2023/11/08 16:33:57 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
size_t		gnl_ft_strlen(const char *str);
char		*gnl_ft_strjoin(const char *dest, char *str);
char		*gnl_ft_strchr(const char *str, int c);
char		*gnl_ft_strdup(const char *str);
size_t		gnl_ft_strlcpy(char *dest, const char *str, size_t n);

#endif