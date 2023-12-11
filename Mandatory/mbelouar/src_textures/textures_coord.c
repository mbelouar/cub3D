/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:38:03 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/11 00:09:11 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	find_x_texture(t_data *data, int i, mlx_texture_t *texture)
{
	float	hit_coord;
	float	tile;

	tile = (float)data->map_info.square_s;
	if (data->ray[i].hit_vertical == 1)
		hit_coord = data->ray[i].wallhit_y;
	else
		hit_coord = data->ray[i].wallhit_x;
	if (hit_coord >= 0 && hit_coord < WIDTH)
		data->hold.x_text = fmod(hit_coord, tile) * (texture->width / tile);
}

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
void	find_y_texture(t_data *data, int start)
{
	data->hold.y_text = ((float)data->hold.texture->height
			/ data->project.wall_height) * (data->project.wall_top - start);
}

void	draw_texture(t_data *data, int i)
{
	int	start;

	start = data->project.wall_top;
	data->project.wall_top = data->project.wall_top
		* (data->project.wall_top > 0);
	if (data->project.wall_bottom > HEIGHT)
		data->project.wall_bottom = HEIGHT;
	while (data->project.wall_top < data->project.wall_bottom)
	{
		find_y_texture(data, start);
		mlx_put_pixel(data->image.img, i, data->project.wall_top,
			get_texture_color(data->hold.x_text,
				data->hold.y_text, data->hold.texture));
		if (data->hold.y_text < 0)
			data->hold.y_text = 0;
		if (data->hold.y_text >= data->hold.texture->height)
			data->hold.y_text = data->hold.texture->height - 1;
		data->project.wall_top++;
	}
}

void	setup_texture(t_data *data, int i)
{
	if (data->ray[i].hit_vertical != 1
		&& data->ray[i].ray_angle >= 0
		&& data->ray[i].ray_angle < M_PI)
		data->hold.texture = data->text.tex_no;
	else if (data->ray[i].hit_vertical != 1
		&& data->ray[i].ray_angle >= M_PI
		&& data->ray[i].ray_angle < 2 * M_PI)
		data->hold.texture = data->text.tex_so;
	else if (data->ray[i].hit_vertical == 1
		&& data->ray[i].ray_angle >= M_PI / 2
		&& data->ray[i].ray_angle < 3 * M_PI / 2)
		data->hold.texture = data->text.tex_we;
	else
		data->hold.texture = data->text.tex_ea;
}
