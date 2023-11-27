/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:34:25 by matesant          #+#    #+#             */
/*   Updated: 2023/11/27 16:09:23 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_map_errors(char *str, t_game *matrice)
{
	ft_printf("%s", str);
	if (matrice->map.fill)
		ft_delete_matrice(matrice->map.fill);
	if (matrice->map.map)
		ft_delete_matrice(matrice->map.map);
	if (matrice->mlx_ptr)
		mlx_terminate(matrice->mlx_ptr);
	exit(1);
}

void	ft_exit_file(char *str)
{
	ft_printf("%s", str);
	exit(1);
}
