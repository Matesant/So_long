/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:45 by matesant          #+#    #+#             */
/*   Updated: 2023/10/23 16:45:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <stdio.h>

#define WINDOW_WIDTH 6000
#define WINDOW_HEIGTH 1000

int	main(void)
{
	t_long jorge;
	t_long tobias;
	t_long mana;

	jorge.azul = 10;
	tobias.azul = 20;
	mana.azul = 30;
	
	printf("%d\n,%d\n, %d\n", jorge.azul, tobias.azul, mana.azul);
}