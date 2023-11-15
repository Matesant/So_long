/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:29:49 by matesant          #+#    #+#             */
/*   Updated: 2023/11/15 20:20:18 by vboxuser         ###   ########.fr       */
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
	matrice->map.ppos.x = 0;
	matrice->map.ppos.y = 0;
}

void	ft_cmap(char *path, t_game *matrice)
{
	char	*map;
	char	*temp;

	map = ft_strdup("");
	matrice->file.fd = open(path, O_RDONLY);
	while (1)
	{
		matrice->file.line = get_next_line(matrice->file.fd);
		if (!matrice->file.line)
			break ;
		temp = map;
		map = ft_strjoin(map, matrice->file.line);
		free(matrice->file.line);
		free(temp);
	}
	matrice->map.map = ft_split(map, '\n');
	ft_labla(matrice);
	free (map);
	close(matrice->file.fd);
}

int	main(int argc, char **argv)
{
	t_game	maurice;

	if (argc != 2)
		ft_map_errors("Invalid number of arguments", NULL);
	ft_init_counters(&maurice);
	ft_cmap(argv[1], &maurice);
	ft_map_format(&maurice);
	ft_matrice_dup(&maurice);
	ft_flood_fill(&maurice, maurice.map.ppos.x, maurice.map.ppos.y);
	if (maurice.counter.collect != 0 || maurice.counter.exit != 0)
	{
		ft_map_errors("Map can't be completed\n", &maurice);
	}
	ft_map_errors("Bye bye\n", &maurice);
}
