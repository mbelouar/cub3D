/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:19:52 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/05 22:37:15 by mbelouar         ###   ########.fr       */
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

// void	draw_texture(t_data *data, int i)
// {

// }

// void	setup_texture(t_data *data, int i)
// {
// 	if (data->ray[i].rayAngle >= 0 && data->ray[i].rayAngle < M_PI)
// 		// Player is facing south
// 	else if (data->ray[i].rayAngle >= M_PI && data->ray[i].rayAngle < 2 * M_PI)
// 		// Player is facing north
// 	else if (data->ray[i].rayAngle >= M_PI / 2 && data->ray[i].rayAngle < 3 * M_PI / 2)
// 		// Player is facing east
// 	else
// 		// Player is facing west
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
		// fishbowl eye
		float	corrected_dist = data->ray[i].distance * cos(data->ray[i].rayAngle - data->r_angle);

		// wall height
		int	wall_Height = 32000 / corrected_dist;

		// wall starting point
		int wall_topPixel = (HEIGHT / 2) - (wall_Height / 2);
		if (wall_topPixel < 0)
			wall_topPixel = 0;

		// wall ending point
		int wall_bottomPixel = (HEIGHT / 2) + (wall_Height / 2);
		if (wall_bottomPixel > HEIGHT)
			wall_bottomPixel = HEIGHT;

		// setup_textures(data, i);
		// find_x_texture(data, i);
		// find_y_texture(data, i);
		// draw_texture(data, i);
		j = wall_topPixel;
		while (j < wall_bottomPixel)
		{
			if (i <= WIDTH && i >=0 && j >= 0 && j <= HEIGHT)
				mlx_put_pixel(data->image.img, i, j, generate_color(0,0,0,255));
			j++;
		}
		i++;
	}
}

