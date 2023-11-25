/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:12:00 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/25 16:41:59 by mbelouar         ###   ########.fr       */
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

void	ft_move_left(t_data *data)
{
	data->x_tmp -= cos(data->r_angle + M_PI / 2) * SPEED_MOVE;
	data->y_tmp -= sin(data->r_angle + M_PI / 2) * SPEED_MOVE;
}

void	ft_move_right(t_data *data)
{
	data->x_tmp += cos(data->r_angle + M_PI / 2) * SPEED_MOVE;
	data->y_tmp += sin(data->r_angle + M_PI / 2) * SPEED_MOVE;
}
