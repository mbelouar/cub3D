/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:25:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 23:28:26 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

float	dist_two_points(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

static void	check_calculate_dist(t_data *data, float h_d, float v_d, int i)
{
	if (v_d <= h_d)
	{
		data->ray[i].distance = v_d;
		data->ray[i].wallhit_x = data->hold.verthit_x;
		data->ray[i].wallhit_y = data->hold.verthit_y;
		data->ray[i].hit_vertical = 1;
	}
	else
	{
		data->ray[i].distance = h_d;
		data->ray[i].wallhit_x = data->hold.horzhit_x;
		data->ray[i].wallhit_y = data->hold.horzhit_y;
		data->ray[i].hit_vertical = 0;
	}

}

void	calculate_dis(t_data *data, int i)
{
	float	horz_hit_dist;
	float	vert_hit_dist;

	if (data->hold.foundhorz_hit == 1)
		horz_hit_dist = dist_two_points(data->player._x, data->player._y,
				data->hold.horzhit_x, data->hold.horzhit_y);
	else
		horz_hit_dist = INT_MAX;
	if (data->hold.foundvert_hit == 1)
		vert_hit_dist = dist_two_points(data->player._x, data->player._y,
				data->hold.verthit_x, data->hold.verthit_y);
	else
		vert_hit_dist = INT_MAX;
	check_calculate_dist(data, horz_hit_dist, vert_hit_dist, i);
}

void	cast_ray(t_data *data, int i)
{
	setup_rot_angle(&data->ray->ray_angle);
	horz_inter(data, data->ray->ray_angle);
	vert_inter(data, data->ray->ray_angle);
	calculate_dis(data, i);
}

void	cast_all_rays(t_data *data)
{
	int		i;
	float	step;

	step = (float)FOV_ANGLE / WIDTH;
	i = 0;
	data->ray->ray_angle = data->r_angle - (FOV_ANGLE / 2);
	while (i < WIDTH)
	{
		data->ray[i].ray_angle = data->ray->ray_angle;
		cast_ray(data, i);
		data->ray->ray_angle += step;
		i++;
	}
	data->ray[0].ray_angle = data->r_angle - (FOV_ANGLE / 2);
}
