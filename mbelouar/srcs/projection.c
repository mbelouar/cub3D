/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:19:52 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/25 16:42:16 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_roof(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT / 2)
		{
			mlx_put_pixel(data->image.img, i, j, generate_color(0,123,94,255));
			j++;
		}
		i++;
	}
}

void	draw_floor(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = HEIGHT / 2;
		while (j < HEIGHT)
		{
			mlx_put_pixel(data->image.img, i, j, generate_color(252,210,14,255));
			j++;
		}
		i++;
	}
}

void	generate3D_projection(t_data *data)
{
	int	i;
	int	j;
	int	S;

	i = 0;
	S = data->map_info.square_S;
	while (i < WIDTH)
	{
		// float	corrected_dist = data->ray[i].distance * cos(data->ray[i].rayAngle - data->r_angle);
		float	dist_projec = (WIDTH / 2) / tan(FOV_ANGLE / 2);
		float	projWall_height = (S / data->ray[i].distance) * dist_projec;

		int	wall_Height = (int)projWall_height;

		int wall_topPixel = (HEIGHT / 2) - (wall_Height / 2);
		if (wall_topPixel < 0)
			wall_topPixel = 0;

		int wall_bottomPixel = (HEIGHT / 2) + (wall_Height / 2);
		if (wall_bottomPixel > HEIGHT)
			wall_bottomPixel = HEIGHT;

		j = wall_topPixel;
		while (j < wall_bottomPixel)
		{
			// data->Color_buffer[(WIDTH * j) + i] = 0xFFFFFFFF;
			mlx_put_pixel(data->image.img, i, j, generate_color(207,8,33,255));
			j++;
		}
		i++;
	}
}
