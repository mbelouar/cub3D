/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:39:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 23:36:40 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_wall(t_data *data, float x, float y)
{
	int	index;
	int	line_len;
	int	x_pix;
	int	y_pix;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (1);
	x_pix = (int)floor(x / data->map_info.square_s);
	y_pix = (int)floor(y / data->map_info.square_s);
	index = 0;
	while (data->map_info.map_wt[index])
		index++;
	if (y_pix >= index)
		return (1);
	line_len = ft_strlen(data->map_info.map_wt[y_pix]);
	if (x_pix >= line_len)
		return (1);
	if (data->map_info.map_wt[y_pix][x_pix] == '1')
		return (1);
	return (0);
}

static void	calculate_horz_intercepts(t_data *data, float ray_angle)
{
	data->hold.y_inter = floor(data->player._y / data->map_info.square_s)
		* data->map_info.square_s;
	if (data->hold.is_facedown)
		data->hold.y_inter += data->map_info.square_s;
	else
		data->hold.y_inter += 0;
	data->hold.x_inter = data->player._x
		+ (data->hold.y_inter - data->player._y) / tan(ray_angle);
}

static void	calculate_horz_xystep(t_data *data, float ray_angle)
{
	data->hold.y_step = data->map_info.square_s;
	if (data->hold.is_faceup)
		data->hold.y_step *= -1;
	else
		data->hold.y_step *= 1;
	data->hold.x_step = data->map_info.square_s / tan(ray_angle);
	if (data->hold.is_faceleft && data->hold.x_step > 0)
		data->hold.x_step *= -1;
	else
		data->hold.x_step *= 1;
	if (data->hold.is_faceright && data->hold.x_step < 0)
		data->hold.x_step *= -1;
	else
		data->hold.x_step *= 1;
}

static void	search_horz_wall_hit(t_data *data)
{
	float	x_tocheck;
	float	y_tocheck;
	int		add_pix;

	if (data->hold.is_faceup)
		add_pix = -1;
	else
		add_pix = 0;
	while (true)
	{
		x_tocheck = data->hold.horznext_x;
		y_tocheck = data->hold.horznext_y + add_pix;
		if (is_wall(data, x_tocheck, y_tocheck))
		{
			data->hold.horzhit_x = data->hold.horznext_x;
			data->hold.horzhit_y = data->hold.horznext_y;
			data->hold.foundhorz_hit = 1;
			break ;
		}
		else
		{
			data->hold.horznext_x += data->hold.x_step;
			data->hold.horznext_y += data->hold.y_step;
		}
	}
}

void	horz_inter(t_data *data, float ray_angle)
{
	data->hold.is_facedown = ray_angle > 0 && ray_angle < M_PI;
	data->hold.is_faceup = !data->hold.is_facedown;
	data->hold.is_faceright = ray_angle < (M_PI / 2)
		|| ray_angle > (3 * M_PI / 2);
	data->hold.is_faceleft = !data->hold.is_faceright;
	calculate_horz_intercepts(data, ray_angle);
	calculate_horz_xystep(data, ray_angle);
	data->hold.horznext_x = data->hold.x_inter;
	data->hold.horznext_y = data->hold.y_inter;
	search_horz_wall_hit(data);
}
