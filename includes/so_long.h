/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:06 by matesant          #+#    #+#             */
/*   Updated: 2023/11/27 16:58:03 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// key hooks
# define W MLX_KEY_W
# define A MLX_KEY_A
# define S MLX_KEY_S
# define D MLX_KEY_D
# define UP MLX_KEY_UP
# define DOWN MLX_KEY_DOWN
# define LEFT MLX_KEY_LEFT
# define RIGHT MLX_KEY_RIGHT
# define P MLX_PRESS
# define R MLX_REPEAT
# define WALL 49
# define COLLECT 67
# define FLOOR 48
# define COLLECT_PNG "assets/collectable.png"

// size image
# define WIDHT_SCREEN 64
# define HEIGHT_SCREEN 64
# define WIDTH 64
# define HEIGHT 64

// 42 libs
# include "../lib/42_libft/libft.h"
# include "../lib/Get_next_line/get_next_line.h"
# include "../lib/Printf/ft_printf.h"

// other libs
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_positions
{
	int				y;
	int				x;
}					t_positions;

// images an cordinates
typedef struct s_draw
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	int				x;
	int				y;
}					t_draw;

typedef struct s_img
{
	t_draw			floor;
	t_draw			wall;
	t_draw			player;
	t_draw			exit;
	t_draw			collect[10000];
}					t_img;

// counter for characters
typedef struct s_counter
{
	int				collect;
	int				walls;
	int				player;
	int				floor;
	int				exit;
	int				collect_fill;
}					t_counter;

// get the fd and the gnl line
typedef struct s_file
{
	char			*line;
	int				fd;
	char			*fill;
}					t_file;

// ms is for map size
// player_p && exit_p for player position
// map is for my map duh
typedef struct s_map
{
	char			**map;
	char			**fill;
	t_positions		ppos;
	size_t			x;
	size_t			y;
}					t_map;

// main struct
typedef struct s_game
{
	mlx_t			*mlx_ptr;
	void			*win_ptr;
	t_map			map;
	t_counter		counter;
	t_file			file;
	int				count;
	int				steps;
	t_img			img;
}					t_game;

// map checkers
void				ft_verify_char(t_game *matrice, int c, int x, int y);
void				ft_loop_char(t_game *matrice);
void				ft_validate_file(char *file);
void				ft_map_format(t_game *matrice);
void				ft_verify_char(t_game *matrice, int c, int x, int y);
void				ft_matrice_lines_columns(t_game *matrice);

// error handling && finishing
void				ft_map_errors(char *str, t_game *matrice);
void				ft_delete_all(t_game *matrice);
void				ft_delete(t_game *matrice);
void				ft_exit_file(char *str);

// flood fill functions
void				ft_flood_fill(t_game *matrice, int x, int y);
void				ft_close_fill(char *str, t_game *matrice);
void				ft_print_matrice(char **matrice);

// mlx functions
void				ft_start_mlx(t_game *matrice);

// image functions
t_draw				image_load(void *mlx, char *path);
void				load_path(char **path);
void				all_image(t_game *matrice);
void				init_collect(t_game *game, int x, int y, int *count);

// key hooks
void				key_hooks(mlx_key_data_t key_args, void *param);
void				ft_collect(t_game *check, int x, int y);
void				ft_init_exit(t_game *map, int x, int y);

#endif