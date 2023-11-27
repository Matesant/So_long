/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:57:40 by matesant          #+#    #+#             */
/*   Updated: 2023/11/27 16:07:55 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long._bonus.h"

int	ft_verify_path(t_game *check, int x, int y);

void	move_sid(t_game *map, int x, int y)
{
	if (ft_verify_path(map, x, y))
	{
		map->img.player.img->instances[0].x = x;
		map->img.player.img->instances[0].y = y;
		ft_printf("movement: %d\n", map->steps++);
	}
	ft_collect(map, x, y);
	ft_init_exit(map, x, y);
	return ;
}

void	key_hooks(mlx_key_data_t key_args, void *param)
{
	t_game	*map;
	int		x;
	int		y;

	map = (t_game *)param;
	y = map->img.player.img->instances[0].y;
	x = map->img.player.img->instances[0].x;
	if (key_args.key == MLX_KEY_ESCAPE)
		mlx_close_window(map->mlx_ptr);
	else if ((key_args.key == W || key_args.key == UP) && (key_args.action == P
			|| key_args.action == R))
		move_sid(map, x, y - 64);
	else if ((key_args.key == S || key_args.key == DOWN)
		&& (key_args.action == P || key_args.action == R))
		move_sid(map, x, y + 64);
	else if ((key_args.key == A || key_args.key == LEFT)
		&& (key_args.action == P || key_args.action == R))
		move_sid(map, x - 64, y);
	else if ((key_args.key == D || key_args.key == RIGHT)
		&& (key_args.action == P || key_args.action == R))
		move_sid(map, x + 64, y);
}

int	ft_verify_path(t_game *check, int x, int y)
{
	int	i;

	i = -1;
	while (++i < check->counter.walls)
	{
		if (check->img.wall.img->instances[i].x == x
			&& check->img.wall.img->instances[i].y == y)
			return (0);
	}
	return (1);
}

void	ft_collect(t_game *check, int x, int y)
{
	int	i;
	int	collect_x;
	int	collect_y;

	collect_x = 0;
	collect_y = 0;
	if (check->map.map && check->map.map[y / HEIGHT][x / WIDTH] == COLLECT)
	{
		check->map.map[y / HEIGHT][x / WIDTH] = FLOOR;
		i = 0;
		while (i < check->counter.collect)
		{
			collect_x = check->img.collect[i].x;
			collect_y = check->img.collect[i].y;
			if (collect_x == x && collect_y == y)
			{
				mlx_delete_image(check->mlx_ptr, check->img.collect[i].img);
				check->count--;
				break ;
			}
			i++;
		}
	}
}

void	ft_init_exit(t_game *map, int x, int y)
{
	if (map->img.exit.img->instances[0].x == x
		&& map->img.exit.img->instances[0].y == y && map->count == 0)
		ft_map_errors("Exit found!\n", map);
}
