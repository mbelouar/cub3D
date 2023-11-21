/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:40:11 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/20 17:24:05 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	vert_inter(t_data *data, double ray_angle, int i)
{
    data->hold.is_FaceDown = ray_angle > 0 && ray_angle < M_PI;
	data->hold.is_FaceUp = !data->hold.is_FaceDown;

	data->hold.is_FaceRight = ray_angle < (M_PI / 2) || ray_angle > (3 * M_PI / 2);
	data->hold.is_FaceLeft = !data->hold.is_FaceRight;

    // horz_inter
    data->hold.foundVert_hit = 0;
	data->hold.horzHit_x = 0;
	data->hold.horzHit_y = 0;

    data->hold.x_inter = floor(data->player._x / data->map_info.square_S) * data->map_info.square_S;
	data->hold.x_inter += data->hold.is_FaceRight ? data->map_info.square_S : 0;

	data->hold.y_inter = data->player._y + (data->hold.x_inter - data->player._x) * tan(ray_angle);

    // calculate xstep and ystep
    data->hold.x_step = data->map_info.square_S;
	data->hold.x_step *= data->hold.is_FaceLeft ? -1 : 1;

	data->hold.y_step = data->map_info.square_S * tan(ray_angle);
	data->hold.y_step *= (data->hold.is_FaceUp && data->hold.y_step > 0) ? -1 : 1;
	data->hold.y_step *= (data->hold.is_FaceDown && data->hold.y_step < 0) ? -1 : 1;

    //
    data->hold.next_x = data->hold.x_inter;
	data->hold.next_y = data->hold.y_inter;

    //increment xstep and ystep until find a wall hit
	while (data->hold.next_x >= 0 && data->hold.next_x <= HEIGHT
			&& data->hold.next_y >= 0 && data->hold.next_y <= WIDTH)
	{
		double x_toCheck = data->hold.next_y + (data->hold.is_FaceLeft ? -1 : 0);
		double y_toCheck = data->hold.next_x;

		if (is_wall(data, x_toCheck, y_toCheck))
		{
			data->ray[i].wallHit_x = data->hold.next_x;
			data->ray[i].wallHit_y = data->hold.next_y;
			data->hold.foundVert_hit = 1;
			break;
		}
		else
		{
			data->hold.next_x += data->hold.x_step;
			data->hold.next_y += data->hold.y_step;
		}
	}
}
