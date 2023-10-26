/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:45 by matesant          #+#    #+#             */
/*   Updated: 2023/10/26 16:46:58 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WINDOW_X 600
#define WINDOW_Y 100

//fecha tudo aqui e é isso
int	destroy(t_long *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

//testador de telca ESC beta
int	keyword(int keycode, t_long *data)
{
	if (keycode == XK_Escape)
		destroy(data);
	return (0);
}

int	main(void)
{
	t_long	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_X, WINDOW_Y,
			"tony marrone");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	//mlx_key_hook(data.win_ptr, keyword, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &keyword, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
