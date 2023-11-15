/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:06 by matesant          #+#    #+#             */
/*   Updated: 2023/11/15 20:52:46 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//player size
# define WIDHT 30
# define HEIGHT 16

// size of screen
# define WIDHT_SCREEN 599
# define HEIGHT_SCREEN 1000

// 42 libs
# include "../lib/42_libft/libft.h"
# include "../lib/Printf/ft_printf.h"
# include "../lib/Get_next_line/get_next_line.h"

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

// counter for characters
typedef struct s_counter
{
	int			collect;
	int			walls;
	int			player;
	int			floor;
	int			exit;
}				t_counter;

// get the fd and the gnl line
typedef struct s_file
{
	char		*line;
	int			fd;
}				t_file;

// ms is for map size
// player_p && exit_p for player position
// map is for my map duh
typedef struct s_map
{
	char		**map;
	char		**fill;
	t_thunder	ppos;
	t_thunder	exit_p;
	t_thunder	ms;
	size_t		x;
	size_t		y;
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

// map checkers
void			ft_verify_char(t_game *matrice, int c, int x, int y);
void			ft_labla(t_game *matrice);
void			ft_validate_file(char *file);
void			ft_map_format(t_game *matrice);
void			ft_verify_char(t_game *matrice, int c, int x, int y);
void			ft_matrice_lines_columns(t_game *matrice);

// error handling
void			ft_map_errors(char *str, t_game *matrice);

// flood fill functions
void			ft_flood_fill(t_game *matrice, int x, int y);
void			ft_matrice_dup(t_game *matrice);
void			ft_print_matrice(t_game *matrice);

// mlx functions

#endif