/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:33:13 by vboxuser          #+#    #+#             */
/*   Updated: 2023/11/15 19:41:52 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mudar o cabeçalho
//muda em

#include "so_long.h"

void	ft_flood_fill(t_game *matrice, int x, int y)
{
	if (matrice->map.fill[y][x] == '1')
		return ;
	matrice->map.fill[y][x] = 'X';
	ft_print_matrice(matrice);
	ft_flood_fill(matrice, x + 1, y);
	ft_printf("x = %d, y = %d\n", x, y);
}
