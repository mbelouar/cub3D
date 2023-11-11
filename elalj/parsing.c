/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:56:57 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/07 12:56:58 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_valid_directions(t_data *data)
{
	check_if_double_directions(data);
	//check_if_valid_direction_name(data);
}
int	map_valid(t_data *data, int fd)
{
	read_map(data, fd);
	check_valid_directions(data);
	return (1);
}
