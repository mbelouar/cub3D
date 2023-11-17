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
	update_position(data, x, y);
}

void	ft_move_down(t_data *data)
{
	double	x;
	double	y;

	x = data->ray.player_x - cos(data->r_angle) * SPEED_MOVE;
	y = data->ray.player_y - sin(data->r_angle) * SPEED_MOVE;
	update_position(data, x, y);
}

void    ft_move_left(t_data *data)
{
	double    x;
    double    y;

	x = data->ray.player_x - cos(data->r_angle + M_PI / 2) * SPEED_MOVE;
    y = data->ray.player_y - sin(data->r_angle + M_PI / 2) * SPEED_MOVE;
    update_position(data, x, y);
}

void ft_move_right(t_data *data)
{
    double x;
    double y;

    x = data->ray.player_x + cos(data->r_angle + M_PI / 2) * SPEED_MOVE;
    y = data->ray.player_y + sin(data->r_angle + M_PI / 2) * SPEED_MOVE;
    update_position(data, x, y);
}

void update_position(t_data *data, double x, double y)
{
    if (valid_move(data, x, y) == 0)
    {
        data->ray.player_x = x;
        data->ray.player_y = y;
    }
}


int valid_move(t_data *data, double x, double y)
{
    // Calculate the grid indices for the new position
    int new_x = (int)x;
    int new_y = (int)y;
    int S = data->map_info.square_S;

    // Check if the new position is within the boundaries of the map
    if (data->map_info.map_wt[(new_x + 1) / S][new_y / S] == '0' ||
        data->map_info.map_wt[(new_x - 1) / S][new_y / S] == '0' ||
        data->map_info.map_wt[new_x / S][(new_y + 1) / S] == '0' ||
        data->map_info.map_wt[new_x / S][(new_y - 1) / S] == '0')
    {
        // Check if the new position corresponds to an open space on the map
        if (data->map_info.map[new_y / S][new_x / S] == '0')
        {
            // The move is valid
			// update the position
            return (0);
        }
    }
    // The move is not valid
    return (1);
}
