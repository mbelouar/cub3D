/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:40:11 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/19 21:41:17 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	vert_inter(t_data *data, double ray_angle, int i)
{
    int	isFace_Down = ray_angle > 0 && ray_angle < M_PI;
	int	isFace_Up = !isFace_Down;

	int isFace_Right = ray_angle < (M_PI / 2) || ray_angle > (3 * M_PI / 2);
	int isFace_Left = !isFace_Right;

    // horz_inter
    int foundHorz_hit = 0;
	double horzHit_x = 0;
	double horzHit_y = 0;
	int	horzContent = 0;

    x_inter = floor(data->ray.player_x / data->map_info.square_S) * data->map_info.square_S;
	x_inter += isFace_Right ? data->map_info.square_S : 0;

	y_inter = data->ray.player_y + (x_inter - data->ray.player_x) * tan(ray_angle);

    // calculate xstep and ystep
    y_step = data->map_info.square_S;
	y_step *= isFace_Up ? -1 : 1;

	x_step = data->map_info.square_S * tan(ray_angle);
	x_step *= (isFace_Left && y_step > 0) ? -1 : 1;
	x_step *= (isFace_Right && y_step < 0) ? -1 : 1;

    //
    double next_x = x_inter;
	double next_y = y_inter;

    //increment xstep and ystep until find a wall hit
	while (next_x >= 0 && next_x <= WIDTH && next_y >= 0 && next_y <= HEIGHT)
	{
		double x_toCheck = next_x;
		double y_toCheck = next_y + (isFace_Up ? -1 : 0);

		if (is_wall(x_toCheck, y_toCheck))
		{
			data->ray[i].wallHit_x = next_x;
			data->ray[i].wallHit_y = next_y;
			foundHorz_hit = 1;
			break;
		}
		else
		{
			next_x += x_step;
			next_y += y_step;
		}
	}
}
