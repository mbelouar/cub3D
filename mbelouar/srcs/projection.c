/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:19:52 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/08 23:45:39 by mbelouar         ###   ########.fr       */
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
void find_y_texture(t_data *data, mlx_texture_t *texture, int top, int bottom)
{
	// Ensure that the top and bottom values are within the valid range
	if (top < 0)
		top = 0;

	if (bottom > HEIGHT)
		bottom = HEIGHT;

	// Calculate the y_text based on the middle of the wall
	data->hold.y_text = (float)(top + (bottom - top) / 2 - (HEIGHT / 2))
		* (float)texture->height / (float)(bottom - top);
}


// void	find_y_texture(t_data *data, mlx_texture_t *texture, int top, int bottom)
// {
// 	(void)texture;
// 	// printf("wall top = %d\nwall bottom = %d\n", top, bottom);
// 	if (top > 0 && top < HEIGHT)
// 	{
// 		// printf("heyy\n");
// 		data->hold.y_text = (top - ((HEIGHT / 2) + ((bottom - top) / 2)))
// 			* (data->map_info.square_S / (bottom - top));
// 		// data->hold.y_text = (1 - (bottom - top)
// 		// 		/ (bottom - top)) * texture->height;
// 	}
// }

void draw_texture(t_data *data, int i, int top, int bottom)
{
	// Calculate the starting y coordinate for drawing the texture

	find_y_texture(data, data->hold.texture, top, bottom);
	while (top < bottom)
	{
		if (top >= 0 && top < HEIGHT)
		{
			mlx_put_pixel(data->image.img, i, top,
				get_texture_color(data->hold.x_text, data->hold.y_text, data->hold.texture));
		}
		// Increment y_text for the next pixel
		// printf("%f\n", data->hold.y_text) ;
		data->hold.y_text += (float)data->hold.texture->height / (bottom - top);
		// Ensure y_text is within the valid range of the texture
		if (data->hold.y_text < 0)
			data->hold.y_text = 0;

		if (data->hold.y_text >= data->hold.texture->height)
			data->hold.y_text = data->hold.texture->height - 1;
		// if (data->hold.y_text < 0 || data->hold.y_text >= data->hold.texture->height)
		// {
			// printf("tex height = %d\n", data->hold.texture->height);
			// printf("tex width = %d\n", data->hold.texture->width);
			// printf("y = %d\n", (int)data->hold.y_text);
			// printf("x = %d\n", (int)data->hold.x_text);
		// }
		top++;
	}
}

// void	draw_texture(t_data *data, int i, int top, int bottom)
// {
// 	while (top < bottom)
// 	{
// 		find_y_texture(data, data->hold.texture, top, bottom);
// 		if (top >= 0 && top < HEIGHT)
// 			mlx_put_pixel(data->image.img, i, top,
// 				get_texture_color(data->hold.x_text, data->hold.y_text, data->hold.texture));
// 		top++;
// 	}
// }

void	setup_texture(t_data *data, int i)
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
		float	dist_projec = (WIDTH / 2) / tan(FOV_ANGLE / 2);
		float	projWall_height = (S / corrected_dist) * dist_projec;

		int	wall_Height = (int)projWall_height;
		// int wall_Height = 26000 / corrected_dist;

		// wall starting point
		int wall_topPixel = (HEIGHT / 2) - (wall_Height / 2);
		if (wall_topPixel < 0)
			wall_topPixel = 0;

		// wall ending point
		int wall_bottomPixel = (HEIGHT / 2) + (wall_Height / 2);
		if (wall_bottomPixel > HEIGHT)
			wall_bottomPixel = HEIGHT;
		data->hold.texture = data->text.tex_we;
		// setup_texture(data, i);
		// if (data->ray[i].wasHitVertical == 1)
		// 	data->hold.x_text = (int)data->ray[i].wallHit_y % S;
		// else
		// 	data->hold.x_text = (int)data->ray[i].wallHit_x % S;
		find_x_texture(data, i, data->hold.texture);
		draw_texture(data, i, wall_topPixel, wall_bottomPixel);
		// j = data->ray[i].wall_topPixel;
		// while (j < data->ray[i].wall_bottomPixel)
		// {
		// 	if (i <= WIDTH && i >=0 && j >= 0 && j <= HEIGHT)
		// 		mlx_put_pixel(data->image.img, i, j, generate_color(0,0,0,255));
		// 	j++;
		// }
		i++;
	}
}

