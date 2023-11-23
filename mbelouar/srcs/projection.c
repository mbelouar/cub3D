/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:19:52 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/23 22:39:52 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	clearColor_buffer(t_data *data, unsigned int color)
{
	int i;
	int j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			data->Color_buffer[(WIDTH * j) + i] = color;
			mlx_put_pixel(data->image.img, i, j, color);
			j++;
		}
		i++;
	}
}

void	generate3D_projection(t_data *data)
{
	int	i;
	int j;
	int	S;

	i = 0;
	S = data->map_info.square_S;
	while (i < WIDTH)
	{
		// double	perp_dist = data->ray[i].distance * cos(data->ray[i].rayAngle - data->r_angle);
		double	dist_projec = (WIDTH / 2) / tan(FOV_ANGLE / 2);
		double	projWall_height = (S / data->ray[i].distance) * dist_projec;

		int	wall_Height = (int)projWall_height;
		int wall_topPixel = (HEIGHT / 2) - (wall_Height / 2);
		wall_topPixel = wall_topPixel < 0 ? 0 : wall_topPixel;

		int wall_bottomPixel = (HEIGHT / 2) + (wall_Height / 2);
		wall_bottomPixel = wall_topPixel > HEIGHT ? HEIGHT : wall_bottomPixel;

		j = wall_topPixel;
		while (j < wall_bottomPixel)
		{
			data->Color_buffer[(WIDTH * j) + i] = 0xFFFFFFFF;
			mlx_put_pixel(data->image.img, i, j, 0xFFFFFFFF);
			j++;
		}

		i++;
	}
}
