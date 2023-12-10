/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:48:53 by moelalj           #+#    #+#             */
/*   Updated: 2023/12/10 00:07:41 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	extension_err(void)
{
	ft_putstr_fd("Error\n  ->invalid extension of the map\n", 2);
	exit (1);
}

void	not_surr_err(void)
{
	ft_putstr_fd("Error\n  ->The map is not surrounded by walls\n", 2);
	exit (1);
}

void	around_spaces_err(void)
{
	ft_putstr_fd("Error:\n  ->Player can suicide :)\n", 2);
	exit (1);
}

void	double_directions_err(void)
{
	ft_putstr_fd("Error:\n  ->Found float directions><\n", 2);
	exit (1);
}

void	non_directions_err(void)
{
	ft_putstr_fd("Error:\n  ->can not found the spawning orientation/player", 2);
	exit (1);
}
