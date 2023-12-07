/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:19:52 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/06 21:23:36 by mbelouar         ###   ########.fr       */
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

static void	find_x_texture(t_data *data, int i, mlx_texture_t *texture)
{
	float tile;

	tile = data->map_info.square_S;
	if (data->ray[i].wasHitVertical == 1)
	{
		data->hold.x_text = fmod(data->ray[i].wallHit_y, tile)
			* (texture->width / tile);
	}
	else
	{
		if (data->ray[i].wallHit_x >= 0
			&& data->ray[i].wallHit_x < WIDTH)
			data->hold.x_text = fmod(data->ray[i].wallHit_x, tile)
				* (texture->width / tile);
	}
}

static void	find_y_texture(t_data *data, int i, mlx_texture_t *texture)
{
	if (data->ray[i].wall_topPixel > 0 && data->ray[i].wall_topPixel < HEIGHT)
		data->hold.y_text = (1 - (data->ray[i].wall_bottomPixel
					- data->ray[i].wall_topPixel)
				/ data->ray[i].wall_height) * texture->height;
}

static void	draw_texture(t_data *data, int i)
{
	while (data->ray[i].wall_topPixel < data->ray[i].wall_bottomPixel
		&& data->ray[i].wall_topPixel < HEIGHT)
	{
		find_y_texture(data, i, data->hold.texture);
		if (data->ray[i].wall_topPixel >= 0
			&& data->ray[i].wall_topPixel < HEIGHT)
		mlx_put_pixel(data->image.img, i, data->ray[i].wall_topPixel,
			get_texture_color(data->hold.x_text, data->hold.y_text, data->hold.texture));
		data->ray[i].wall_topPixel++;
	}
}

static void	setup_texture(t_data *data, int i)
{
	if (data->ray[i].rayAngle >= 0 && data->ray[i].rayAngle < M_PI)
		data->hold.texture = data->text.tex_so;
	else if (data->ray[i].rayAngle >= M_PI && data->ray[i].rayAngle < 2 * M_PI)
		data->hold.texture = data->text.tex_no;
	else if (data->ray[i].rayAngle >= M_PI / 2 && data->ray[i].rayAngle < 3 * M_PI / 2)
		data->hold.texture = data->text.tex_ea;
	else
		data->hold.texture = data->text.tex_we;
}

void	generate3D_projection(t_data *data)
{
	int	i;
	// int	j;
	int	S;
	float	corrected_dist;

	i = 0;
	S = data->map_info.square_S;
	while (i < WIDTH)
	{
		// fishbowl eye
		corrected_dist = data->ray[i].distance * cos(data->ray[i].rayAngle - data->r_angle);

		// wall height
		data->ray[i].wall_Height = 32000 / corrected_dist;

		// wall starting point
		data->ray[i].wall_topPixel = (HEIGHT / 2) - (data->ray[i].wall_Height / 2);
		// if (data->ray[i].wall_topPixel < 0)
		// 	data->ray[i].wall_topPixel = 0;

		// wall ending point
		data->ray[i].wall_bottomPixel = (HEIGHT / 2) + (data->ray[i].wall_Height / 2);
		// if (data->ray[i].wall_bottomPixel > HEIGHT)
		// 	data->ray[i].wall_bottomPixel = HEIGHT;

		setup_texture(data, i);
		find_x_texture(data, i, data->hold.texture);
		draw_texture(data, i);
		// j = data->ray[i].wall_topPixel;
		// while (j < data->ray[i].wall_bottomPixel)
		// {
		// 	if (i <= WIDTH && i >=0 && j >= 0 && j <= HEIGHT)
		// 		mlx_put_pixel(data->image.img, i, j, generate_color(0,0,0,255));
		// 	j++;
		// }
		++i;
	}
}

