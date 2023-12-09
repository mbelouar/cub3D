/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:19:52 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/09 22:58:48 by mbelouar         ###   ########.fr       */
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

void	find_x_texture(t_data *data, int i, mlx_texture_t *texture)
{
	float hit_coord;
	float tile;

	tile = (float)data->map_info.square_S;
	if (data->ray[i].wasHitVertical == 1)
		hit_coord = data->ray[i].wallHit_y;
	else
		hit_coord = data->ray[i].wallHit_x;
	if (hit_coord >= 0 && hit_coord < WIDTH)
		data->hold.x_text = fmod(hit_coord, tile) * (texture->width / tile);
}
void	find_y_texture(t_data *data, int top, int height, int start)
{
/*
	y = a * top + b = ?;
	top == start:
		tex[y = 0]
	top == start + height
		tex[y = tex.h]

	y(top = start) = 0 = a * start + b => b = -a * start;
	y(top = start + h) = tex.h => tex.h = a * (start + h) - a * start
								tex.h = a * h => a = tex.h/h
	y = tex.h/h * top - tex.h/h * start
	  = tex.h/h * (top - start);
*/
	data->hold.y_text = ((float)data->hold.texture->height/height)
		* (top - start);
}

void	draw_texture(t_data *data, int i, int top, int bottom, int height)
{
	int	start;

	start = top;
	top = top * (top > 0);
	if (bottom > HEIGHT)
		bottom = HEIGHT;
	while (top < bottom)
	{
		find_y_texture(data, top, height, start);
		mlx_put_pixel(data->image.img, i, top,
			get_texture_color(data->hold.x_text, data->hold.y_text, data->hold.texture));
		if (data->hold.y_text < 0)
			data->hold.y_text = 0;
		if (data->hold.y_text >= data->hold.texture->height)
			data->hold.y_text = data->hold.texture->height - 1;
		top++;
	}
}

void	setup_texture(t_data *data, int i)
{
	if (data->ray[i].wasHitVertical != 1
		&& data->ray[i].rayAngle >= 0
			&& data->ray[i].rayAngle < M_PI)
			data->hold.texture = data->text.tex_no;
	else if (data->ray[i].wasHitVertical != 1
		&& data->ray[i].rayAngle >= M_PI
			&& data->ray[i].rayAngle < 2 * M_PI)
		data->hold.texture = data->text.tex_so;
	else if (data->ray[i].wasHitVertical == 1
		&& data->ray[i].rayAngle >= M_PI / 2
			&& data->ray[i].rayAngle < 3 * M_PI / 2)
			data->hold.texture = data->text.tex_we;
	else
			data->hold.texture = data->text.tex_ea;
}

void	generate3D_projection(t_data *data)
{
	int		i;
	int		wall_Height;
	int		wall_topPixel;
	int		wall_bottomPixel;
	float	corrected_dist;

	i = 0;
	while (i < WIDTH)
	{
		corrected_dist = data->ray[i].distance * cos(data->ray[i].rayAngle - data->r_angle);
		wall_Height = 13000 / corrected_dist;
		// float	dist_projec = (WIDTH / 2) / tan(FOV_ANGLE / 2);
		// float	projWall_height = (data->map_info.square_S / corrected_dist) * dist_projec;

		// wall_Height = (int)projWall_height;
		wall_topPixel = (HEIGHT / 2) - (wall_Height / 2);
		wall_bottomPixel = (HEIGHT / 2) + (wall_Height / 2);
		// data->hold.texture = data->text.tex_so;
		setup_texture(data, i);
		find_x_texture(data, i, data->hold.texture);
		draw_texture(data, i, wall_topPixel, wall_bottomPixel, wall_Height);
		i++;
	}
}

