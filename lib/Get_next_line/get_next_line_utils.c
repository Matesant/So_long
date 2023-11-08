/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:05:27 by matesant          #+#    #+#             */
/*   Updated: 2023/11/08 16:32:42 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*gnl_ft_strjoin(const char *dest, char *str)
{
	size_t	i;
	size_t	j;
	char	*newstring;

	i = 0;
	j = 0;
	newstring = (char *)malloc(gnl_ft_strlen(dest) + gnl_ft_strlen(str) + 1);
	if (newstring == NULL)
		return (NULL);
	while (dest && dest[i])
	{
		newstring[i] = dest[i];
		i++;
	}
	while (str[j])
	{
		newstring[i] = str[j];
		i++;
		j++;
	}
	free((char *)dest);
	newstring[i] = '\0';
	return (newstring);
}

char	*gnl_ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

size_t	gnl_ft_strlcpy(char *dest, const char *str, size_t n)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!str)
		return (0);
	str_len = gnl_ft_strlen(str);
	while (str[i] && i < n - 1)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (str_len);
}

char	*gnl_ft_strdup(const char *str)
{
	int		i;
	char	*allocate;

	i = 0;
	allocate = malloc(gnl_ft_strlen(str) + 1);
	if (allocate == NULL)
		return (NULL);
	while (str[i])
	{
		allocate[i] = str[i];
		i++;
	}
	allocate[i] = '\0';
	return (allocate);
}
