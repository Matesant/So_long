/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:45 by matesant          #+#    #+#             */
/*   Updated: 2023/11/29 16:16:15 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_enemies(t_game *game, int x, int y, int *count);

void	ft_put_window(t_game *matrice, int c, int x, int y)
{
	if (c == '1')
		mlx_image_to_window(matrice->mlx_ptr, matrice->img.wall.img, x, y);
	else if (c == 'P')
		mlx_image_to_window(matrice->mlx_ptr, matrice->img.player.img, x, y);
	else if (c == 'C')
		init_collect(matrice, x, y, &matrice->count);
	else if (c == 'E')
		mlx_image_to_window(matrice->mlx_ptr, matrice->img.exit.img, x, y);
	else if (c == 'K')
		init_enemies(matrice, x, y, &matrice->count2);
}

void	ft_put(t_game *matrice)
{
	int	i;
	int	j;

	mlx_image_to_window(matrice->mlx_ptr, matrice->img.floor.img, 0, 0);
	i = -1;
	while (matrice->map.map[++i])
	{
		j = -1;
		while (matrice->map.map[i][++j])
		{
			ft_put_window(matrice, matrice->map.map[i][j], j * 64, i * 64);
		}
	}
}

void	ft_start_mlx(t_game *matrice)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	matrice->mlx_ptr = mlx_init(WIDHT_SCREEN * matrice->map.x, HEIGHT_SCREEN
		* matrice->map.y, "so_long", true);
	if (!matrice->mlx_ptr)
		ft_map_errors("Error mlx_init\n", matrice);
	all_image(matrice);
	ft_put(matrice);
}

void	moves(t_game *matrice)
{
	static mlx_image_t	*move_img;
	char				*counter;

	if (move_img)
		mlx_delete_image(matrice->mlx_ptr, move_img);
	counter = ft_itoa(matrice->move);
	mlx_put_string(matrice->mlx_ptr, "steps:", 0, 0);
	move_img = mlx_put_string(matrice->mlx_ptr, counter, 70, 0);
	free(counter);
	matrice->move++;
}

void	init_enemies(t_game *game, int x, int y, int *count)
{
	place_coin(game, &game->img.enemy[*count].img, ENEMY_PNG);
	mlx_image_to_window(game->mlx_ptr, game->img.enemy[*count].img, x, y);
	(*count)++;
}
