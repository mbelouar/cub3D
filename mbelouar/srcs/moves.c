/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:00 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/17 01:51:12 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_move_up(t_data *data)
{
	double	x;
	double	y;

	x = data->ray.player_x + cos(data->r_angle) * SPEED_MOVE;
	y = data->ray.player_y + sin(data->r_angle) * SPEED_MOVE;
	if (valid_move(data, x, y))
		return ;
}

void	ft_move_down(t_data *data)
{
	double	x;
	double	y;

	x = data->ray.player_x - cos(data->r_angle) * SPEED_MOVE;
	y = data->ray.player_y - sin(data->r_angle) * SPEED_MOVE;
	if (valid_move(data, x, y))
		return;
}

void    ft_move_left(t_data *data)
{
	double    x;
    double    y;

	x = data->ray.player_x - cos(data->r_angle + M_PI / 2) * SPEED_MOVE;
    y = data->ray.player_y - sin(data->r_angle + M_PI / 2) * SPEED_MOVE;

    if (valid_move(data, x, y))
        return;
}

void ft_move_right(t_data *data)
{
    double x;
    double y;

    x = data->ray.player_x + cos(data->r_angle + M_PI / 2) * SPEED_MOVE;
    y = data->ray.player_y + sin(data->r_angle + M_PI / 2) * SPEED_MOVE;

    if (valid_move(data, x, y))
        return;
}

int valid_move(t_data *data, double x, double y)
{
    // Calculate the grid indices for the new position
    int new_x = (int)x;
    int new_y = (int)y;

    // Check if the new position is within the boundaries of the map
    if (new_x >= 0 && new_x < data->map_info.map_width &&
        new_y >= 0 && new_y < data->map_info.map_height)
    {
        // Check if the new position corresponds to an open space on the map
        if (data->map_info.map[new_y][new_x] == '0')
        {
            // The move is valid
			// update the position
			data->ray.player_x = x;
            data->ray.player_y = y;
            return (1);
        }
    }
    // The move is not valid
    return (0);
}
