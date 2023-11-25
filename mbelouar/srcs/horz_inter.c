/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:39:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/25 17:18:01 by mbelouar         ###   ########.fr       */
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

void	horz_inter(t_data *data, float ray_angle)
{
	data->hold.is_FaceDown = ray_angle > 0 && ray_angle < M_PI;
	data->hold.is_FaceUp = !data->hold.is_FaceDown;

	data->hold.is_FaceRight = ray_angle < (M_PI / 2) || ray_angle > (3 * M_PI / 2);
	data->hold.is_FaceLeft = !data->hold.is_FaceRight;

    // horz_inter
    data->hold.y_inter = floor(data->player._y / data->map_info.square_S) * data->map_info.square_S;
	data->hold.y_inter += data->hold.is_FaceDown ? data->map_info.square_S : 0;

	data->hold.x_inter = data->player._x + (data->hold.y_inter - data->player._y) / tan(ray_angle);

    // calculate xstep and ystep
    data->hold.y_step = data->map_info.square_S;
	data->hold.y_step *= data->hold.is_FaceUp ? -1 : 1;

	data->hold.x_step = data->map_info.square_S / tan(ray_angle);
	data->hold.x_step *= (data->hold.is_FaceLeft && data->hold.x_step > 0) ? -1 : 1;
	data->hold.x_step *= (data->hold.is_FaceRight && data->hold.x_step < 0) ? -1 : 1;

    //
    data->hold.HorzNext_x = data->hold.x_inter;
	data->hold.HorzNext_y = data->hold.y_inter;
    //increment xstep and ystep until find a wall hit
	while (true)
	{
		float x_toCheck = data->hold.HorzNext_x;
		float y_toCheck = data->hold.HorzNext_y + (data->hold.is_FaceUp ? -1 : 0);
		if (is_wall(data, x_toCheck, y_toCheck))
		{
			data->hold.horzHit_x = data->hold.HorzNext_x;
			data->hold.horzHit_y = data->hold.HorzNext_y;
			data->hold.foundHorz_hit = 1;
			break;
		}
		else
		{
			data->hold.HorzNext_x += data->hold.x_step;
			data->hold.HorzNext_y += data->hold.y_step;
		}
	}
}
