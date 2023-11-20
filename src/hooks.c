/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:57:40 by matesant          #+#    #+#             */
/*   Updated: 2023/11/19 22:54:16 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hooks(mlx_key_data_t key_args, void *param)
{
	t_game	*matrice;

	matrice = (t_game *)param;
	if (key_args.key == MLX_KEY_ESCAPE)
		mlx_close_window(matrice->mlx_ptr);
}
