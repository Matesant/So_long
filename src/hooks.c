/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:57:40 by matesant          #+#    #+#             */
/*   Updated: 2023/11/21 21:48:16 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_verify_path(t_game *check, int x, int y, int i);
void	ft_collect(t_game *check, int x, int y);

void	move_sid(int i, t_game *map, int x, int y)
{
	if (i == 1 && ((!(ft_verify_path(map, x, y, 1) == 0))))
		map->img.player.img->instances[0].y -= 64;
	else if (i == 2 && ((!(ft_verify_path(map, x, y, 2) == 0))))
		map->img.player.img->instances[0].y += 64;
	else if (i == 3 && ((!(ft_verify_path(map, x, y, 3) == 0))))
		map->img.player.img->instances[0].x -= 64;
	else if (i == 4 && ((!(ft_verify_path(map, x, y, 4) == 0))))
		map->img.player.img->instances[0].x += 64;
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
		move_sid(1, map, *x, *y);
	else if ((key_args.key == S || key_args.key == DOWN)
		&& (key_args.action == P || key_args.action == R))
		move_sid(2, map, *x, *y);
	else if ((key_args.key == A || key_args.key == LEFT)
		&& (key_args.action == P || key_args.action == R))
		move_sid(3, map, *x, *y);
	else if ((key_args.key == D || key_args.key == RIGHT)
		&& (key_args.action == P || key_args.action == R))
		move_sid(4, map, *x, *y);
	ft_collect(map, *x, *y);
}

int	ft_verify_path(t_game *check, int x, int y, int i)
{
	if (i == 1 && check->map.map[(y - HEIGHT) / HEIGHT][x / WIDTH] == WALL)
		return (0);
	else if (i == 2 && check->map.map[(y + HEIGHT) / HEIGHT][x / WIDTH] == WALL)
		return (0);
	else if (i == 3 && check->map.map[y / HEIGHT][(x - WIDTH) / WIDTH] == WALL)
		return (0);
	else if (i == 4 && check->map.map[y / HEIGHT][(x + WIDTH) / WIDTH] == WALL)
		return (0);
	else
		return (1);
}

void	ft_collect(t_game *check, int x, int y)
{
	//int	i;
	//int	collect_x;
	//int	collect_y;

	//collect_x = 0;
	//collect_y = 0;
	if (check->map.map && check->map.map[y / HEIGHT][x / WIDTH] == COLLECT)
	{
		check->map.map[y / HEIGHT][x / WIDTH] = FLOOR;
		//i = 1;
		ft_printf("Collect: %d\n", check->map.map[y / HEIGHT][x / WIDTH]);
		/*while (i < check->counter.collect)
		{
			collect_x = check->img.collect[i].img->instances[0].x;
			printf("collectx: %d\n", collect_x);
			collect_y = check->img.collect[i].img->instances[0].y;
			printf("collecty: %d\n", collect_y);
			printf("i: %d\n", i);
			i++;
		}*/
	}
}
