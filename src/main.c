/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:29:49 by matesant          #+#    #+#             */
/*   Updated: 2023/11/12 17:39:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		i;
	t_game	maurice;

	i = -1;
	if (argc != 2)
		ft_map_errors("Invalid number of arguments", NULL);
	ft_init_counters(&maurice);
	ft_cmap(argv[1], &maurice);
	ft_map_format(&maurice);
	ft_delete_matrice(maurice.map.map);
}
