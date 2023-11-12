/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:34:25 by matesant          #+#    #+#             */
/*   Updated: 2023/11/12 14:08:40 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_errors(int i, t_game *matrice)
{
	if (i == 1)
	{
		ft_printf("Invalid map\n");
		ft_delete_matrice(matrice->map.map);
	}
	if (i == 2)
		ft_printf("Wrong map extension\n");
	if (i == 3)
	{
		ft_printf("Invalid read\n");
		close(matrice->file.fd);
	}
	if (i == 4) 
		ft_printf("Invalid arguments\n");
	exit(1);
}
