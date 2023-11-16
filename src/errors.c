/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:34:25 by matesant          #+#    #+#             */
/*   Updated: 2023/11/16 17:49:06 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_errors(char *str, t_game *matrice)
{
	ft_printf("%s", str);
	if (matrice)
	{
		//ft_print_matrice(matrice->map.fill);
		if (matrice->map.fill)
			ft_delete_matrice(matrice->map.fill);
		//ft_print_matrice(matrice->map.map);
		if (matrice->map.map)
			ft_delete_matrice(matrice->map.map);
	}
	exit(1);
}
