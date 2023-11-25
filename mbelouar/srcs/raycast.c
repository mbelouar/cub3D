/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:25:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/25 16:42:35 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

float	dist_two_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

static void	check_calculate_dist(t_data *data, float h_d, float v_d, int i)
{
	if (v_d <= h_d)
	{
		data->ray[i].distance = v_d;
		data->ray[i].wallHit_x = data->hold.vertHit_x;
		data->ray[i].wallHit_y = data->hold.vertHit_y;
		data->ray[i].wasHitVertical = 1;
	}
	else
	{
		data->ray[i].distance = h_d;
		data->ray[i].wallHit_x = data->hold.horzHit_x;
		data->ray[i].wallHit_y = data->hold.horzHit_y;
		data->ray[i].wasHitVertical = 0;
	}
}

void	calculate_dis(t_data *data, int i)
{
	float horzHit_dist;
	float vertHit_dist;

	if (data->hold.foundHorz_hit == 1)
		horzHit_dist = dist_two_points(data->player._x, data->player._y,
				data->hold.horzHit_x, data->hold.horzHit_y);
	else
		horzHit_dist = INT_MAX;
	if (data->hold.foundVert_hit == 1)
		vertHit_dist = dist_two_points(data->player._x, data->player._y,
				data->hold.vertHit_x, data->hold.vertHit_y);
	else
		vertHit_dist = INT_MAX;
	check_calculate_dist(data, horzHit_dist, vertHit_dist, i);
}

void	cast_ray(t_data *data, int i)
{
	setup_rot_angle(data);
	horz_inter(data, data->ray->rayAngle);
	vert_inter(data, data->ray->rayAngle);
	calculate_dis(data, i);
}

void	castAll_rays(t_data *data)
{
	int	i;

	i = 0;
	data->ray->rayAngle = data->r_angle - (FOV_ANGLE / 2);
	while (i < WIDTH)
	{
		cast_ray(data, i);
		data->ray->rayAngle += FOV_ANGLE / WIDTH;
		i++;
	}
}
