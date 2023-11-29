/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:33:13 by matesant          #+#    #+#             */
/*   Updated: 2023/11/29 18:10:15 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_game *matrice, int x, int y)
{
	if (matrice->map.fill[y][x] == '1' || matrice->map.fill[y][x] == 'X')
		return ;
	else if (matrice->map.fill[y][x] == 'C')
		matrice->counter.collect_fill--;
	else if (matrice->map.fill[y][x] == 'E')
		matrice->counter.exit--;
	matrice->map.fill[y][x] = 'X';
	ft_flood_fill(matrice, x + 1, y);
	ft_flood_fill(matrice, x - 1, y);
	ft_flood_fill(matrice, x, y + 1);
	ft_flood_fill(matrice, x, y - 1);
}
