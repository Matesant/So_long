/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:06:07 by matesant          #+#    #+#             */
/*   Updated: 2023/11/21 22:29:54 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_draw	image_load(void *mlx, char *path)
{
	t_draw	img;

	img.texture = mlx_load_png(path);
	img.img = mlx_texture_to_image(mlx, img.texture);
	mlx_delete_texture(img.texture);
	return (img);
}

void	load_path(char **path)
{
	path[0] = "assets/player.png";
	path[1] = "assets/wall.png";
	path[2] = "assets/floor.png";
	path[3] = "assets/exit.png";
	path[4] = "assets/enimy.png";
}

void	all_image(t_game *matrice)
{
	char	*path[6];

	load_path(path);
	matrice->img.floor = image_load(matrice->mlx_ptr, path[2]);
	matrice->img.wall = image_load(matrice->mlx_ptr, path[1]);
	matrice->img.player = image_load(matrice->mlx_ptr, path[0]);
	matrice->img.exit = image_load(matrice->mlx_ptr, path[3]);
}
void	place_coin(t_game *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*img = mlx_texture_to_image(game->mlx_ptr, texture);
	mlx_delete_texture(texture);
}

void	init_collect(t_game *game, int x, int y, int *count)
{
	place_coin(game, &game->img.collect[*count].img, COLLECT_PNG);
	game->img.collect[*count].x = x;
	game->img.collect[*count].y = y;
	mlx_image_to_window(game->mlx_ptr, game->img.collect[*count].img, x, y);
	(*count)++;
}
