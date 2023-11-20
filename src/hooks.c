/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:57:40 by matesant          #+#    #+#             */
/*   Updated: 2023/11/20 18:26:48 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verify_path(t_game *check, int x, int y);

void	move_sid(int i, t_game *map)
{
	if (i == 1 && ((!(ft_verify_path(map, 0, 64) == 1))))
	{
		map->img.player.img->instances[0].y -= 64;
	}
	if (i == 2)
	{
		map->img.player.img->instances[0].y += 64;
	}
	if (i == 3)
	{
		map->img.player.img->instances[0].x -= 64;
	}
	if (i == 4)
	{
		map->img.player.img->instances[0].x += 64;
	}
}

void	key_hooks(mlx_key_data_t key_args, void *param)
{
	t_game	*map;
	int		*x;
	int		*y;

	map = (t_game *)param;
	y = &map->img.player.img->instances[0].y;
	x = &map->img.player.img->instances[0].x;
	if (key_args.key == MLX_KEY_ESCAPE)
		mlx_close_window(map->mlx_ptr);
	else if ((key_args.key == W || key_args.key == UP) && (key_args.action == P
			|| key_args.action == R))
		move_sid(1, map);
	else if ((key_args.key == S || key_args.key == DOWN)
		&& (key_args.action == P || key_args.action == R))
		move_sid(2, map);
	else if ((key_args.key == A || key_args.key == LEFT)
		&& (key_args.action == P || key_args.action == R))
		move_sid(3, map);
	else if ((key_args.key == D || key_args.key == RIGHT)
		&& (key_args.action == P || key_args.action == R))
		move_sid(4, map);
}

int	ft_verify_path(t_game *check, int x, int y)
{
	t_game *map;

	x = 0;
	map = check;
	if (check->map.map[(y - HEIGHT) / HEIGHT][x / WIDTH] == '1')
		return (0);
	return (1);
}
