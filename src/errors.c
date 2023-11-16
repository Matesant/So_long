/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:34:25 by matesant          #+#    #+#             */
/*   Updated: 2023/11/15 20:59:25 by vboxuser         ###   ########.fr       */
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

void	ft_close_fill(char *str, t_game *matrice)
{
	ft_printf("%s", str);
	if (matrice->map.fill)
		ft_delete_matrice(matrice->map.fill);
}
