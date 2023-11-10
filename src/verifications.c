/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:02:23 by matesant          #+#    #+#             */
/*   Updated: 2023/11/10 16:49:16 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verify_char(t_map *matrice)
{
	int	i;
	int	j;

	i = 0;
	while (matrice->map[i])
	{
		j = 0;
		while (matrice->map[i][j])
		{
			if (matrice->map[i][j] == 'C')
				ft_printf("boa");
			else if (matrice->map[i][j] == 'E')
				ft_printf("boa");
			else if (matrice->map[i][j] == 'P')
				ft_printf("boa");
			else if (matrice->map[i][j] == '1')
				ft_printf("boa");
			else
				ft_printf("Invalid map\n");
			j++;
		}
		i++;
	}
}

void	ft_cmap(char *map, t_map *matrice)
{
	int		fd;
	char	line[1000000];
	int		i;
	ssize_t	bytes;

	i = 0;
	fd = open(map, O_RDONLY);
	bytes = read(fd, &line, 100000);
	if (bytes == -1)
	{
		perror("Error\n");
		exit(1);
	}
	matrice->map = ft_split(line, '\n');
	ft_verify_char(matrice);
	while (matrice->map[i])
		ft_printf("%s\n", matrice->map[i++]);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_map	maurice;

	if (argc == 2)
	{
		ft_cmap(argv[1], &maurice);
	}
}
