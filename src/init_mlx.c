/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:45 by matesant          #+#    #+#             */
/*   Updated: 2023/11/19 22:36:27 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_window(t_game *matrice, int c, int x, int y)
{
	int	i;

	i = -1;
	if (c == '1')
		mlx_image_to_window(matrice->mlx_ptr, matrice->lucas.wall.img, x, y);
	else if (c == 'P')
		mlx_image_to_window(matrice->mlx_ptr, matrice->lucas.player.img, x, y);
	else if (c == 'C')
		mlx_image_to_window(matrice->mlx_ptr, matrice->lucas.collect[++i].img,
			x, y);
	else if (c == 'E')
		mlx_image_to_window(matrice->mlx_ptr, matrice->lucas.exit.img, x, y);
}

void	ft_put(t_game *matrice)
{
	int	i;
	int	j;
	int	widht;
	int	height;

	widht = matrice->map.x * 64;
	height = matrice->map.y * 64;
	mlx_resize_image(matrice->lucas.floor.img, widht, height);
	mlx_image_to_window(matrice->mlx_ptr, matrice->lucas.floor.img, 0, 0);
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
