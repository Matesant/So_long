#include "so_long.h"

void ft_matrice_dup(t_game *matrice)
{
	size_t	i;
	size_t	j;

	i = -1;
	matrice->map.fill = malloc(sizeof(char *) * (matrice->map.y + 1));
	while (++i < matrice->map.y)
	{
		matrice->map.fill[i] = malloc(sizeof(char) * (matrice->map.x + 1));
		j = -1;
		while (++j < matrice->map.x)
		{
			matrice->map.fill[i][j] = matrice->map.map[i][j];
		}
		matrice->map.fill[i][j] = '\0';
	}
}
