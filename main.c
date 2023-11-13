/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:49:18 by matesant          #+#    #+#             */
/*   Updated: 2023/11/13 20:01:59 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/42_libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	ssize_t	bytes;
	char	buffer[1024];
	int		fd;
	char	**map;
	int		y;
	int		x;

	fd = open("map.ber", O_RDONLY);
	bytes = read(fd, buffer, 1024);
	map = ft_split(buffer, '\n');
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		free(map[y]);
		y++;
	}
	close(fd);
	free(map);
}
