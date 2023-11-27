/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:29:49 by matesant          #+#    #+#             */
/*   Updated: 2023/11/27 16:51:29 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_assign(t_game *matrice)
{
	mlx_key_hook(matrice->mlx_ptr, &key_hooks, matrice);
}

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
	matrice->counter.collect_fill = 0;
	matrice->count = 0;
	matrice->steps = 1;
	matrice->move = 1;
	matrice->mlx_ptr = NULL;
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
	matrice->map.fill = ft_split(map, '\n');
	free(map);
	close(matrice->file.fd);
	ft_labla(matrice);
}

int	main(int argc, char **argv)
{
	t_game	matrice;

	if (argc != 2)
		ft_map_errors("Invalid number of arguments\n", NULL);
	ft_init_counters(&matrice);
	ft_validate_file(argv[1]);
	ft_cmap(argv[1], &matrice);
	ft_map_format(&matrice);
	ft_flood_fill(&matrice, matrice.map.ppos.x, matrice.map.ppos.y);
	if (matrice.counter.collect_fill != 0 || matrice.counter.exit != 0)
		ft_map_errors("Map can't be finished\n", &matrice);
	ft_start_mlx(&matrice);
	key_assign(&matrice);
	mlx_loop(matrice.mlx_ptr);
	ft_map_errors("Thank you bye bye matane\n", &matrice);
}
