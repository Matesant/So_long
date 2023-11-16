/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:45 by matesant          #+#    #+#             */
/*   Updated: 2023/11/16 19:41:29 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_wondwo(t_game *matrice, int c, int x, int y)
{
	if (c == '1')
		mlx_image_to_window(matrice->mlx_ptr, matrice->lucas.wall.img, x, y);
	else if (c == 'P')
		mlx_image_to_window(matrice->mlx_ptr, matrice->lucas.player.img, x, y);
	else if (c == '0')
		mlx_image_to_window(matrice->mlx_ptr, matrice->lucas.floor.img, x, y);
}

void	ft_put(t_game *matrice)
{
	int	i;
	int	j;

	i = -1;
	while (matrice->map.map[++i])
	{
		j = -1;
		while (matrice->map.map[i][++j])
		{
			ft_put_wondwo(matrice, matrice->map.map[i][j], j * 64, i * 64);
		}
	}
}

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
	/*	path[3] = "assets/exit.png";
		path[4] = "assets/enimy.png";
		path[5] = "assets/collectable.png";*/
}

void	all_image(t_game *matrice)
{
	char	*path[3];

	load_path(path);
	matrice->lucas.floor = image_load(matrice->mlx_ptr, path[2]);
	matrice->lucas.wall = image_load(matrice->mlx_ptr, path[1]);
	matrice->lucas.player = image_load(matrice->mlx_ptr, path[0]);
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
