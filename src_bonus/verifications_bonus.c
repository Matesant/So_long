/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:02:23 by matesant          #+#    #+#             */
/*   Updated: 2023/11/27 16:09:16 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_rush_00(t_game *neo)
{
	int	y;
	int	x;

	y = 0;
	ft_matrice_lines_columns(neo);
	while (neo->map.map[y])
	{
		if (neo->map.x != ft_strlen(neo->map.map[y]) || neo->map.x < 12)
			ft_map_errors("Invalid map size\n", neo);
		x = -1;
		while (neo->map.map[y][++x])
		{
			if (neo->map.map[0][x] != '1')
				ft_map_errors("Invalid map walls\n", neo);
			else if (neo->map.map[y][0] != '1')
				ft_map_errors("Invalid map walls\n", neo);
			else if (neo->map.map[y][neo->map.x - 1] != '1')
				ft_map_errors("Invalid map walls\n", neo);
			else if (neo->map.map[neo->map.y - 1][x] != '1')
				ft_map_errors("Invalid map walls\n", neo);
		}
		y++;
	}
	if (neo->map.x * 64 > 1920 || neo->map.y * 64 > 1080)
		ft_map_errors("Invalid map size\n", neo);
}

void	ft_map_format(t_game *matrice)
{
	ft_rush_00(matrice);
	if (matrice->counter.collect == 0)
		ft_map_errors("Wrong number of collectibles", matrice);
	if (matrice->counter.exit != 1)
		ft_map_errors("Wrong number of exits", matrice);
	if (matrice->counter.walls < 12)
		ft_map_errors("Wrong number of walls", matrice);
	if (matrice->counter.player != 1)
		ft_map_errors("Wrong number of players", matrice);
}

void	ft_labla(t_game *matrice)
{
	int	y;
	int	x;

	y = -1;
	while (matrice->map.map[++y])
	{
		x = -1;
		while (matrice->map.map[y][++x])
		{
			if (!ft_strchr("CEP10K", matrice->map.map[y][x]))
				ft_map_errors("Invalid character", matrice);
			ft_verify_char(matrice, matrice->map.map[y][x], y, x);
		}
	}
}

void	ft_verify_char(t_game *matrice, int c, int y, int x)
{
	if (c == 'C')
	{
		matrice->counter.collect++;
		matrice->counter.collect_fill++;
	}
	else if (c == 'E')
		matrice->counter.exit++;
	else if (c == 'P')
	{
		matrice->counter.player++;
		matrice->map.ppos.y = y;
		matrice->map.ppos.x = x;
	}
	else if (c == '1')
		matrice->counter.walls++;
	else if (c == '0')
		matrice->counter.floor++;
}

void	ft_validate_file(char *file)
{
	int		fd;
	char	*line;
	char	line2;

	line2 = '\0';
	if (ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) != 0)
		ft_exit_file("Invalid file\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_file("Invalid file\n");
	read(fd, &line2, 1);
	if (line2 == '\n')
		ft_exit_file("Invalid file\n");
	line = get_next_line(fd);
	if (line == NULL || line[0] == '\0' || line[0] == '\n' || line[0] == '\r')
	{
		close(fd);
		free(line);
		ft_exit_file("Invalid file\n");
	}
	close(fd);
	free(line);
}
