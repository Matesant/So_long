/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:33:13 by vboxuser          #+#    #+#             */
/*   Updated: 2023/11/15 20:43:57 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mudar o cabeçalho
//muda em

#include "so_long.h"

void	ft_flood_fill(t_game *matrice, int x, int y)
{
	if (matrice->map.fill[y][x] == '1' || matrice->map.fill[y][x] == 'X')
		return ;
	else if (matrice->map.fill[y][x] == 'C')
		matrice->counter.collect--;
	else if (matrice->map.fill[y][x] == 'E')
		matrice->counter.exit--;
	matrice->map.fill[y][x] = 'X';
	ft_flood_fill(matrice, x + 1, y);
	ft_flood_fill(matrice, x - 1, y);
	ft_flood_fill(matrice, x, y + 1);
	ft_flood_fill(matrice, x, y - 1);
}

void	ft_matrice_dup(t_game *matrice)
{
	size_t	i;
	size_t	j;

	i = -1;
	matrice->map.fill = malloc(sizeof(char *) * matrice->map.y + 1);
	while (matrice->map.map[++i])
	{
		j = -1;
		matrice->map.fill[i] = malloc(sizeof(char *) * matrice->map.x + 1);
		while (matrice->map.map[i][++j])
		{
			matrice->map.fill[i][j] = matrice->map.map[i][j];
		}
	}
}
