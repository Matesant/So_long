/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:34:25 by matesant          #+#    #+#             */
/*   Updated: 2023/11/13 12:15:56 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_errors(char *str, t_game *matrice)
{
	ft_printf("%s", str);
	close(matrice->file.fd);
	if (matrice->map.map)
		ft_delete_matrice(matrice->map.map);
	exit(1);
}
