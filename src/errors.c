/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:34:25 by matesant          #+#    #+#             */
/*   Updated: 2023/11/22 15:37:43 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_errors(char *str, t_game *matrice)
{
	ft_printf("%s", str);
	if (matrice)
	{
		if (matrice->map.fill)
			ft_delete_matrice(matrice->map.fill);
		if (matrice->map.map)
			ft_delete_matrice(matrice->map.map);
	}
	if (!matrice->mlx_ptr)
		exit(1);
}

void	ft_delete_all(t_game *matrice)
{
	ft_map_errors("Exit found!\n", matrice);
	ft_delete(matrice);
	mlx_terminate(matrice->mlx_ptr);
}
