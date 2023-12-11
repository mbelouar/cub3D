/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:40:11 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 23:30:39 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	calculate_vert_intercepts(t_data *data, float ray_angle)
{
	data->hold.x_inter = floor(data->player._x / data->map_info.square_s)
		* data->map_info.square_s;
	if (data->hold.is_faceright)
		data->hold.x_inter += data->map_info.square_s;
	else
		data->hold.x_inter += 0;
	data->hold.y_inter = data->player._y
		+ (data->hold.x_inter - data->player._x) * tan(ray_angle);
}

static void	calculate_vert_xystep(t_data *data, float ray_angle)
{
	data->hold.x_step = data->map_info.square_s;
	if (data->hold.is_faceleft)
		data->hold.x_step *= -1;
	else
		data->hold.x_step *= 1;
	data->hold.y_step = data->map_info.square_s * tan(ray_angle);
	if (data->hold.is_faceup && data->hold.y_step > 0)
		data->hold.y_step *= -1;
	else
		data->hold.y_step *= 1;
	if (data->hold.is_facedown && data->hold.y_step < 0)
		data->hold.y_step *= -1;
	else
		data->hold.y_step *= 1;
}

static void	search_vert_wall_hit(t_data *data)
{
	float	x_tocheck;
	float	y_tocheck;
	int		add_pix;

	if (data->hold.is_faceleft)
		add_pix = -1;
	else
		add_pix = 0;
	while (true)
	{
		x_tocheck = data->hold.vertnext_x + add_pix;
		y_tocheck = data->hold.vertnext_y;
		if (is_wall(data, x_tocheck, y_tocheck))
		{
			data->hold.verthit_x = data->hold.vertnext_x;
			data->hold.verthit_y = data->hold.vertnext_y;
			data->hold.foundvert_hit = 1;
			break ;
		}
		else
		{
			data->hold.vertnext_x += data->hold.x_step;
			data->hold.vertnext_y += data->hold.y_step;
		}
	}
}

void	vert_inter(t_data *data, float ray_angle)
{
	data->hold.is_facedown = ray_angle > 0 && ray_angle < M_PI;
	data->hold.is_faceup = !data->hold.is_facedown;
	data->hold.is_faceright = ray_angle < (M_PI / 2)
		|| ray_angle > (3 * M_PI / 2);
	data->hold.is_faceleft = !data->hold.is_faceright;
	calculate_vert_intercepts(data, ray_angle);
	calculate_vert_xystep(data, ray_angle);
	data->hold.vertnext_x = data->hold.x_inter;
	data->hold.vertnext_y = data->hold.y_inter;
	search_vert_wall_hit(data);
}
