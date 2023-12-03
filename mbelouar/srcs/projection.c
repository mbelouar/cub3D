/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:19:52 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/03 21:32:40 by mbelouar         ###   ########.fr       */
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
			mlx_put_pixel(data->image.img, i, j,
				generate_color(data->dir.ceiling[0],
					data->dir.ceiling[1], data->dir.ceiling[2], 255));
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
			mlx_put_pixel(data->image.img, i, j,
				generate_color(data->dir.floor[0],
					data->dir.floor[1], data->dir.floor[2], 255));
			j++;
		}
		i++;
	}
}

// void	find_x_texture(t_data *data, int i)
// {

// }

// void	find_y_texture(t_data *data, int i)
// {

// }

void	generate3D_projection(t_data *data)
{
	int	i;
	int	j;
	int	S;

	i = 0;
	S = data->map_info.square_S;
	while (i < WIDTH)
	{
		float	corrected_dist = data->ray[i].distance * cos(data->ray[i].rayAngle - data->r_angle);
		int	wall_Height = 32000 / corrected_dist;

		int wall_topPixel = (HEIGHT / 2) - (wall_Height / 2);
		if (wall_topPixel < 0)
			wall_topPixel = 0;
		int wall_bottomPixel = (HEIGHT / 2) + (wall_Height / 2);
		if (wall_bottomPixel > HEIGHT)
			wall_bottomPixel = HEIGHT;


		// find_x_texture(data, i);
		// find_y_texture(data, i);
		// draw_texture(data, i);
		j = wall_topPixel;
		while (j < wall_bottomPixel)
		{
			mlx_put_pixel(data->image.img, i, j, generate_color(207,8,33,255));
			j++;
		}
		i++;
	}
}

