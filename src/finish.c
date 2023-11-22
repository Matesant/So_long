/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:25:16 by vboxuser          #+#    #+#             */
/*   Updated: 2023/11/22 15:59:27 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_delete(t_game *matrice)
{
	if (matrice->img.floor.img)
		mlx_delete_image(matrice->mlx_ptr, matrice->img.floor.img);
	if (matrice->img.player.img)
		mlx_delete_image(matrice->mlx_ptr, matrice->img.player.img);
	if (matrice->img.wall.img)
		mlx_delete_image(matrice->mlx_ptr, matrice->img.wall.img);
	if (matrice->img.exit.img)
		mlx_delete_image(matrice->mlx_ptr, matrice->img.exit.img);
}
