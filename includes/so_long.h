/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:06 by matesant          #+#    #+#             */
/*   Updated: 2023/11/12 15:20:19 by matesant         ###   ########.fr       */
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

// error handling
void			ft_map_errors(int i, t_game *matrice);

#endif