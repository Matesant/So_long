/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:02:23 by matesant          #+#    #+#             */
/*   Updated: 2023/11/12 15:16:26 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_format(t_game *matrice)
{
	if (matrice->counter.collect == 0)
		ft_map_errors(1, matrice);
}

void	ft_verify_char(t_game *matrice)
{
	int	i;
	int	j;

	i = 0;
	while (matrice->map.map[i] != '\0')
	{
		j = 0;
		while (matrice->map.map[i][j])
		{
			if (matrice->map.map[i][j] == 'C')
				matrice->counter.collect++;
			else if (matrice->map.map[i][j] == 'E')
				matrice->counter.exit++;
			else if (matrice->map.map[i][j] == 'P')
				matrice->counter.player++;
			else if (matrice->map.map[i][j] == '1')
				matrice->counter.walls++;
			else if (matrice->map.map[i][j] == '0')
				matrice->counter.floor++;
			else
				ft_map_errors(1, matrice);
			j++;
		}
		i++;
		ft_printf("%d\n", matrice->counter.walls);
	}
}

void	ft_cmap(char *path, t_game *matrice)
{
	ssize_t	bytes;

	matrice->file.fd = open(path, O_RDONLY);
	bytes = read(matrice->file.fd, &matrice->file.line, 100000);
	if (bytes == -1)
		ft_map_errors(3, matrice);
	matrice->map.map = ft_split(matrice->file.line, '\n');
	ft_verify_char(matrice);
	close(matrice->file.fd);
}

void	ft_validate_file(char *file)
{
	int	i;

	i = -1;
	while (file[++i])
	{
		if (!(ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4) == 0))
			ft_map_errors(2, NULL);
	}
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
	int		i;
	t_game	maurice;

	i = -1;
	if (argc != 2)
		ft_map_errors(4, NULL);
	ft_init_counters(&maurice);
	ft_cmap(argv[1], &maurice);
	ft_map_format(&maurice);
	ft_delete_matrice(maurice.map.map);
}
