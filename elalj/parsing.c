/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:56:57 by moelalj           #+#    #+#             */
/*   Updated: 2023/11/16 15:44:48 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_valid(t_data *data, int fd, char *file)
{
	check_extension_map(file);
	read_map(data, fd);
	check_valid_directions(data);
	init_directions(data);
	check_directions_needs(data);
	check_colors(data);
	init_maps(data);
	check_map(data);
	return (1);
}
