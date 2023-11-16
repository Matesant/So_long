/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:45 by matesant          #+#    #+#             */
/*   Updated: 2023/11/15 23:07:51 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_start_mlx(t_game *matrice)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	matrice->mlx_ptr = mlx_init(WIDHT_SCREEN * matrice->map.x, \
		HEIGHT_SCREEN * matrice->map.y, "so_long", true);
	if (!matrice->mlx_ptr)
		ft_map_errors("Error mlx_init\n", matrice);
}


