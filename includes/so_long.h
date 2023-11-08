/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:50:06 by matesant          #+#    #+#             */
/*   Updated: 2023/11/08 17:01:44 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDHT 599
# define HEIGHT 1000

// 42 libs
# include "/nfs/homes/matesant/So_long/lib/42_libft/libft.h"
# include "/nfs/homes/matesant/So_long/lib/Get_next_line/get_next_line.h"
# include "/nfs/homes/matesant/So_long/lib/Printf/ft_printf.h"

// other libs
# include "../MLX42/include/MLX42/MLX42.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_thunder
{
	int			y;
	int			x;
}				t_thunder;

typedef struct s_image
{
	t_thunder	size;
}				t_image;

//main struct
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_game;

#endif