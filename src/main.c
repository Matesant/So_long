/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:29:49 by matesant          #+#    #+#             */
/*   Updated: 2023/11/14 19:09:04 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_matrice_lines_columns(t_game *matrice)
{
	matrice->map.x = 0;
	matrice->map.x = ft_strlen(matrice->map.map[0]);
	matrice->map.y = 0;
	while (matrice->map.map[matrice->map.y])
		matrice->map.y++;
}

void	ft_init_counters(t_game *matrice)
{
	matrice->counter.collect = 0;
	matrice->counter.walls = 0;
	matrice->counter.player = 0;
	matrice->counter.floor = 0;
	matrice->counter.exit = 0;
}

int	main(int argc, char **argv)
{
	t_game	maurice;

	if (argc != 2)
		ft_map_errors("Invalid number of arguments", NULL);
	ft_init_counters(&maurice);
	ft_cmap(argv[1], &maurice);
	ft_map_format(&maurice);
	ft_map_errors("Bye bye\n", &maurice);
}
