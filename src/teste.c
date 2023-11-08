/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:45 by matesant          #+#    #+#             */
/*   Updated: 2023/11/08 17:02:22 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIDHT 599
#define HEIGHT 1000

int	main(void)
{
	t_game	game;

	game.mlx_ptr = mlx_init(WIDHT, HEIGHT, "OPA", true);
	mlx_loop(game.mlx_ptr);
	mlx_delete_image(game.mlx_ptr, 0);
}
