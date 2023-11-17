/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:57:40 by matesant          #+#    #+#             */
/*   Updated: 2023/11/17 18:28:25 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hooks(void *param)
{
	t_game	*matrice;
	mlx_key_data_t key_args;

	matrice = (t_game *)param;
	if (key_args.key == MLX_KEY_ESC)
		mlx_loop_end(key_args.mlx_ptr);
}