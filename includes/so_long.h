/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:06 by matesant          #+#    #+#             */
/*   Updated: 2023/11/12 17:41:47 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDHT 30
# define HEIGHT 16

// 42 libs
# include "/nfs/homes/matesant/So_long/lib/42_libft/libft.h"
# include "/nfs/homes/matesant/So_long/lib/Printf/ft_printf.h"

// other libs
//# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_thunder
{
	int			y;
	int			x;
}				t_thunder;

typedef struct s_counter
{
	int			collect;
	int			walls;
	int			player;
	int			floor;
	int			exit;
}				t_counter;

typedef struct s_file
{
	char		line[1000000];
	int			fd;
}				t_file;

typedef struct s_map
{
	char		**map;
	char		**fill;
	t_thunder	player_p;
	t_thunder	exit_p;
	t_thunder	map_size;
	int			x;
	int			y;
}				t_map;

// main struct
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_counter	counter;
	t_file		file;
}				t_game;

typedef struct s_d
{
	int			i;
	int			j;
}				t_d;

// map checkers
void			ft_verify_char(t_game *matrice, int c, int x, int y);
void			ft_labla(t_game *matrice);
void			ft_validate_file(char *file);
void			ft_map_format(t_game *matrice);
void			ft_verify_char(t_game *matrice, int c, int x, int y);
void			ft_cmap(char *path, t_game *matrice);

// error handling
void			ft_map_errors(char *str, t_game *matrice);

#endif