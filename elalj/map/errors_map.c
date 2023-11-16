/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:48:53 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/13 15:48:54 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
	ft_putstr_fd("Error:\n  ->Found double directions><\n", 2);
	exit (1);
}

void	non_directions_err(void)
{
	ft_putstr_fd("Error:\n  ->can not found the spawning orientation/player", 2);
	exit (1);
}
