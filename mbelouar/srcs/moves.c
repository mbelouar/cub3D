/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:00 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/17 19:58:39 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_move_up(t_data *data, double x_tmp, double y_tmp)
{

    // printf("MOVE UP\n");
    // printf("rot angle ==> %f\n\n", data->r_angle);
	 x_tmp -= cos(data->r_angle) * SPEED_MOVE;
	 y_tmp -= sin(data->r_angle) * SPEED_MOVE;
    // printf("new x ==> %f\n", x);
    // printf("new y ==> %f\n", y);
    // printf("AFTER \nnew x ==> %f\n", data->ray.player_x);
    // printf("new y ==> %f\n", data->ray.player_x);
}

void	ft_move_down(t_data *data, double x_tmp, double y_tmp)
{

    x_tmp += cos(data->r_angle) * SPEED_MOVE;
    y_tmp += sin(data->r_angle) * SPEED_MOVE;
	// printf("new x ==> %f\n", x);
    // printf("new y ==> %f\n", y);
}

void    ft_move_left(t_data *data, double x_tmp, double y_tmp)
{
	 x_tmp -= cos(data->r_angle + M_PI / 2) * SPEED_MOVE;
    printf("%f\n", x_tmp);
     y_tmp -= sin(data->r_angle + M_PI / 2) * SPEED_MOVE;
}

void ft_move_right(t_data *data, double x_tmp, double y_tmp)
{
    x_tmp += cos(data->r_angle + M_PI / 2) * SPEED_MOVE;
    y_tmp += sin(data->r_angle + M_PI / 2) * SPEED_MOVE;
}

void update_position(t_data *data, double x, double y)
{

        data->ray.player_x = x;
        data->ray.player_y = y;
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

// int valid_move(t_data *data, double x, double y)
// {
//     // Calculate the grid indices for the new position
//     int new_x = (int)x;
//     int new_y = (int)y;
//     int S = data->map_info.square_S;

//     // Check if the new position is within the boundaries of the map
//     if (data->map_info.map_wt[(new_x + 1) / S][new_y / S] == '0' ||
//         data->map_info.map_wt[(new_x - 1) / S][new_y / S] == '0' ||
//         data->map_info.map_wt[new_x / S][(new_y + 1) / S] == '0' ||
//         data->map_info.map_wt[new_x / S][(new_y - 1) / S] == '0')
//     {
//         // Check if the new position corresponds to an open space on the map
//         if (data->map_info.map[new_y / S][new_x / S] == '0')
//         {
//             // The move is valid
// 			// update the position
//             return (0);
//         }
//     }
//     // The move is not valid
//     return (1);
// }
