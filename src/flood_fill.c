/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:33:13 by vboxuser          #+#    #+#             */
/*   Updated: 2023/11/15 20:16:58 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mudar o cabeçalho
//muda em

#include "so_long.h"

void	ft_flood_fill(t_game *matrice, int x, int y)
{
	ft_printf("collect = %d\n", matrice->counter.collect);
	if (matrice->map.fill[y][x] == '1' || matrice->map.fill[y][x] == 'X')
		return ;
	else if (matrice->map.fill[y][x] == 'C')
		matrice->counter.collect--;
	ft_printf("collect = %d\n", matrice->counter.collect);
	matrice->map.fill[y][x] = 'X';
	ft_print_matrice(matrice);
	ft_flood_fill(matrice, x + 1, y);
	ft_flood_fill(matrice, x - 1, y);
	ft_flood_fill(matrice, x, y + 1);
	ft_flood_fill(matrice, x, y - 1);
}
