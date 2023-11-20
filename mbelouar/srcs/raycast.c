/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:25:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/20 18:01:27 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double dist_two_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	calculate_dis(t_data *data, int i)
{
	// calculate_dis();
	// calculate both horz and vert hit distances and choose the smallest one
	// must add the two variables foundHorz_hit and foundVert_hit to a struct to hold the data
	double horzHit_dist = data->hold.foundHorz_hit ? dist_two_points(data->player._x, data->player._y, data->hold.horzHit_x, data->hold.horzHit_y)
										: INT_MAX;
	double vertHit_dist = data->hold.foundVert_hit ? dist_two_points(data->player._x, data->player._y, data->hold.vertHit_x, data->hold.vertHit_y)
										: INT_MAX;
	if (vertHit_dist < horzHit_dist)
	{
		data->ray[i].distance = vertHit_dist;
		data->ray[i].wallHit_x = data->hold.vertHit_x;
		data->ray[i].wallHit_y = data->hold.vertHit_y;
		data->ray[i].wasHitVertical = 1;
	}
	else
	{
		data->ray[i].distance = horzHit_dist;
		data->ray[i].wallHit_x = data->hold.horzHit_x;
		data->ray[i].wallHit_y = data->hold.horzHit_y;
		data->ray[i].wasHitVertical = 0;
	}
}

void	cast_ray(t_data *data, double ray_angle, int i)
{
	ray_angle = setup_rot_angle(ray_angle);
	horz_inter(data, ray_angle, i);
	vert_inter(data, ray_angle, i);
	data->ray[i].rayAngle = ray_angle;
	calculate_dis(data, i);
}

void	castAll_rays(t_data *data)
{
    int 	i = 0;
    double	ray_angle = data->r_angle - (FOV_ANGLE / 2);

    while (i < WIDTH)
    {
        cast_ray(data, ray_angle, i);
        ray_angle += FOV_ANGLE / WIDTH;
        i++;
    }
}
