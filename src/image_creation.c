/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:06:07 by matesant          #+#    #+#             */
/*   Updated: 2023/11/17 17:17:51 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_draw	image_load(void *mlx, char *path)
{
	t_draw	img;

	img.texture = mlx_load_png(path);
	img.img = mlx_texture_to_image(mlx, img.texture);
	return (img);
}

void	load_path(char **path)
{
	path[0] = "assets/player.png";
	path[1] = "assets/wall.png";
	path[2] = "assets/floor.png";
	path[3] = "assets/exit.png";
	path[4] = "assets/enimy.png";
	path[5] = "assets/collectable.png";
}

void	all_image(t_game *matrice)
{
	char *path[6];
	int i;

	i = -1;
	load_path(path);
	matrice->lucas.floor = image_load(matrice->mlx_ptr, path[2]);
	matrice->lucas.wall = image_load(matrice->mlx_ptr, path[1]);
	matrice->lucas.player = image_load(matrice->mlx_ptr, path[0]);
	matrice->lucas.exit = image_load(matrice->mlx_ptr, path[3]);
	while (++i < matrice->counter.collect)
		matrice->lucas.collect[i] = image_load(matrice->mlx_ptr, path[5]);
	matrice->lucas.collect[0] = image_load(matrice->mlx_ptr, path[5]);
}