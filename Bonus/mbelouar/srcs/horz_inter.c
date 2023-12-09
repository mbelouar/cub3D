/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:39:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/09 23:49:03 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	is_wall(t_data *data, float x, float y)
{
	int	index;
	int	line_len;
	int	x_pix;
	int	y_pix;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (1);
	x_pix = (int)floor(x / data->map_info.square_S);
	y_pix = (int)floor(y / data->map_info.square_S);
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
	data->hold.y_inter = floor(data->player._y / data->map_info.square_S)
		* data->map_info.square_S;
	if (data->hold.is_FaceDown)
		data->hold.y_inter += data->map_info.square_S;
	else
		data->hold.y_inter += 0;
	data->hold.x_inter = data->player._x
		+ (data->hold.y_inter - data->player._y) / tan(ray_angle);
}

static void	calculate_horz_xystep(t_data *data, float ray_angle)
{
	data->hold.y_step = data->map_info.square_S;
	if (data->hold.is_FaceUp)
		data->hold.y_step *= -1;
	else
		data->hold.y_step *= 1;
	data->hold.x_step = data->map_info.square_S / tan(ray_angle);
	if (data->hold.is_FaceLeft && data->hold.x_step > 0)
		data->hold.x_step *= -1;
	else
		data->hold.x_step *= 1;
	if (data->hold.is_FaceRight && data->hold.x_step < 0)
		data->hold.x_step *= -1;
	else
		data->hold.x_step *= 1;
}

static void	search_horz_wall_hit(t_data *data)
{
	float	x_tocheck;
	float	y_tocheck;
	int		add_pix;

	if (data->hold.is_FaceUp)
		add_pix = -1;
	else
		add_pix = 0;
	while (true)
	{
		x_tocheck = data->hold.HorzNext_x;
		y_tocheck = data->hold.HorzNext_y + add_pix;
		if (is_wall(data, x_tocheck, y_tocheck))
		{
			data->hold.horzHit_x = data->hold.HorzNext_x;
			data->hold.horzHit_y = data->hold.HorzNext_y;
			data->hold.foundHorz_hit = 1;
			break ;
		}
		else
		{
			data->hold.HorzNext_x += data->hold.x_step;
			data->hold.HorzNext_y += data->hold.y_step;
		}
	}
}

void	horz_inter(t_data *data, float ray_angle)
{
	data->hold.is_FaceDown = ray_angle > 0 && ray_angle < M_PI;
	data->hold.is_FaceUp = !data->hold.is_FaceDown;
	data->hold.is_FaceRight = ray_angle < (M_PI / 2)
		|| ray_angle > (3 * M_PI / 2);
	data->hold.is_FaceLeft = !data->hold.is_FaceRight;
	calculate_horz_intercepts(data, ray_angle);
	calculate_horz_xystep(data, ray_angle);
	data->hold.HorzNext_x = data->hold.x_inter;
	data->hold.HorzNext_y = data->hold.y_inter;
	search_horz_wall_hit(data);
}
