/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:39:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/19 21:41:06 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int is_wall(t_data *data, double x, double y)
{
    double x_pix;
    double y_pix;

    x_pix = floor(x / data->map_info.square_S);
    y_pix = floor(y / data->map_info.square_);
    if (x_pix >= data->map_info.map_width || y_pix >= data->map_info.map_height)
        return (1);
    if (data->map_info.map_wt[(int)x_pix][(int)y_pix] == '1')
        return (1);
    return (0);
}

void	horz_inter(t_data *data, double ray_angle, int i)
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

    x_inter = floor(data->ray.player_y / data->map_info.square_S) * data->map_info.square_S;
	x_inter += isFace_Down ? data->map_info.square_S : 0;

	y_inter = data->ray.player_x + (y_inter - data->ray.player_y) / tan(ray_angle);

    // calculate xstep and ystep
    y_step = data->map_info.square_S;
	y_step *= isFace_Up ? -1 : 1;

	x_step = data->map_info.square_S / tan(ray_angle);
	x_step *= (isFace_Left && x_step > 0) ? -1 : 1;
	x_step *= (isFace_Right && x_step < 0) ? -1 : 1;

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
