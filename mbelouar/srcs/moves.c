/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:00 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/20 17:05:04 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_move_up(t_data *data)
{
	 data->x_tmp += cos(data->r_angle) * SPEED_MOVE;
	 data->y_tmp += sin(data->r_angle) * SPEED_MOVE;
}

void	ft_move_down(t_data *data)
{

    data->x_tmp -= cos(data->r_angle) * SPEED_MOVE;
    data->y_tmp -= sin(data->r_angle) * SPEED_MOVE;
}

void    ft_move_left(t_data *data)
{
	 data->x_tmp += cos(data->r_angle - M_PI / 2) * SPEED_MOVE;
     data->y_tmp += sin(data->r_angle - M_PI / 2) * SPEED_MOVE;
}

void ft_move_right(t_data *data)
{
    data->x_tmp -= cos(data->r_angle - M_PI / 2) * SPEED_MOVE;
    data->y_tmp -= sin(data->r_angle - M_PI / 2) * SPEED_MOVE;
}

void update_position(t_data *data, double x, double y)
{

        data->player._x = x;
        data->player._y = y;
}

int valid_move(t_data *data, double x, double y)
{
    int new_x;
    int new_y;
    int S;

    new_x = (int)x;
    new_y = (int)y;
    S = data->map_info.square_S;
    if (data->map_info.map_wt[new_x / S][new_y / S] != '1')
        return (1);
    return (0);
}
