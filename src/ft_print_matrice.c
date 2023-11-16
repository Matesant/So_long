/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:29:33 by vboxuser          #+#    #+#             */
/*   Updated: 2023/11/16 17:15:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_matrice(char **matrice)
{
	int	i;

	i = -1;
	while (matrice[++i])
		ft_printf("%s\n", matrice[i]);
}
