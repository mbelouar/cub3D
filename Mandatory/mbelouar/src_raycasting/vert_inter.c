/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:40:11 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 00:06:55 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	calculate_vert_intercepts(t_data *data, float ray_angle)
{
	data->hold.x_inter = floor(data->player._x / data->map_info.square_S)
		* data->map_info.square_S;
	if (data->hold.is_FaceRight)
		data->hold.x_inter += data->map_info.square_S;
	else
		data->hold.x_inter += 0;
	data->hold.y_inter = data->player._y
		+ (data->hold.x_inter - data->player._x) * tan(ray_angle);
}

static void	calculate_vert_xystep(t_data *data, float ray_angle)
{
	data->hold.x_step = data->map_info.square_S;
	if (data->hold.is_FaceLeft)
		data->hold.x_step *= -1;
	else
		data->hold.x_step *= 1;
	data->hold.y_step = data->map_info.square_S * tan(ray_angle);
	if (data->hold.is_FaceUp && data->hold.y_step > 0)
		data->hold.y_step *= -1;
	else
		data->hold.y_step *= 1;
	if (data->hold.is_FaceDown && data->hold.y_step < 0)
		data->hold.y_step *= -1;
	else
		data->hold.y_step *= 1;
}

static void	search_vert_wall_hit(t_data *data)
{
	float	x_tocheck;
	float	y_tocheck;
	int		add_pix;

	if (data->hold.is_FaceLeft)
		add_pix = -1;
	else
		add_pix = 0;
	while (true)
	{
		x_tocheck = data->hold.VertNext_x + add_pix;
		y_tocheck = data->hold.VertNext_y;
		if (is_wall(data, x_tocheck, y_tocheck))
		{
			data->hold.vertHit_x = data->hold.VertNext_x;
			data->hold.vertHit_y = data->hold.VertNext_y;
			data->hold.foundVert_hit = 1;
			break ;
		}
		else
		{
			data->hold.VertNext_x += data->hold.x_step;
			data->hold.VertNext_y += data->hold.y_step;
		}
	}
}

void	vert_inter(t_data *data, float ray_angle)
{
	data->hold.is_FaceDown = ray_angle > 0 && ray_angle < M_PI;
	data->hold.is_FaceUp = !data->hold.is_FaceDown;
	data->hold.is_FaceRight = ray_angle < (M_PI / 2)
		|| ray_angle > (3 * M_PI / 2);
	data->hold.is_FaceLeft = !data->hold.is_FaceRight;
	calculate_vert_intercepts(data, ray_angle);
	calculate_vert_xystep(data, ray_angle);
	data->hold.VertNext_x = data->hold.x_inter;
	data->hold.VertNext_y = data->hold.y_inter;
	search_vert_wall_hit(data);
}
