/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:02:23 by matesant          #+#    #+#             */
/*   Updated: 2023/11/08 18:52:47 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cmap(char *map, t_map *matrice)
{
	int		fd;
	char	line[1000000];
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	read(fd, &line, 100000);
	matrice->map = ft_split(line, '\n');
	while (matrice->map[i])
		printf("%s\n", matrice->map[i++]);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_map	maurice;

	if (argc == 2)
	{
		ft_cmap(argv[1], &maurice);
	}
}
