/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:29:33 by vboxuser          #+#    #+#             */
/*   Updated: 2023/11/15 19:32:18 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_matrice(t_game *matrice)
{
	int	i;

	i = -1;
	while (matrice->map.fill[++i])
		ft_printf("%s\n", matrice->map.fill[i]);
}
