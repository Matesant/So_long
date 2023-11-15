/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:02:23 by matesant          #+#    #+#             */
/*   Updated: 2023/11/15 20:23:00 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	ft_map_format(t_game *matrice)
{
	ft_rush_00(matrice);
	if (matrice->counter.collect == 0)
		ft_map_errors("Wrong number of collectibles", matrice);
	if (matrice->counter.exit != 1)
		ft_map_errors("Wrong number of exits", matrice);
	if (matrice->counter.floor < 3)
		ft_map_errors("Wrong number of floors", matrice);
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
			ft_verify_char(matrice, matrice->map.map[y][x], x, y);
		}
	}
}

void	ft_verify_char(t_game *matrice, int c, int x, int y)
{
	if (ft_strchr("01CEP", c) == NULL)
		ft_map_errors("Invalid character", matrice);
	if (matrice->map.map[y][x] == 'C')
		matrice->counter.collect++;
	else if (matrice->map.map[y][x] == 'E')
		matrice->counter.exit++;
	else if (matrice->map.map[y][x] == 'P')
	{
		matrice->counter.player++;
		matrice->map.ppos.y = y;
		matrice->map.ppos.x = x;
	}
	else if (matrice->map.map[y][x] == '1')
		matrice->counter.walls++;
	else if (matrice->map.map[y][x] == '0')
		matrice->counter.floor++;
}

void	ft_validate_file(char *file)
{
	int	i;

	i = -1;
	while (file[++i])
	{
		if (!(ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) == 0))
			ft_map_errors("Invalid extension\n", NULL);
	}
}
