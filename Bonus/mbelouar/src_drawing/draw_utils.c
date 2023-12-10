/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:49:26 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/11 00:16:14 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	draw_player(float player_x, float player_y, t_data *data)
{
	float	start_x;
	float	start_y;
	float	curr_x;
	float	curr_y;

	start_x = player_x - data->player.p_size / 2.0;
	start_y = player_y - data->player.p_size / 2.0;
	curr_x = start_x;
	while (curr_x < start_x + data->player.p_size)
	{
		curr_y = start_y;
		while (curr_y < start_y + data->player.p_size)
		{
			mlx_put_pixel(data->image.img,
				curr_x, curr_y, generate_color(0, 0, 0, 255));
			++curr_y;
		}
		++curr_x;
	}
}

void	draw_square(int color, float top, float left, t_data *data)
{
	float	curr_x;
	float	curr_y;

	curr_y = 0;
	while (curr_y < data->map_info.square_s)
	{
		curr_x = 0;
		while (curr_x < data->map_info.square_s)
		{
			if (curr_x + left < WIDTH && curr_y + top < HEIGHT)
				mlx_put_pixel(data->image.img,
					curr_x + left, curr_y + top, color);
			if (curr_x + left < WIDTH && top < HEIGHT)
				mlx_put_pixel(data->image.img,
					curr_x + left, top, generate_color(0, 0, 0, 255));
			curr_x++;
		}
		if (left < WIDTH && curr_y + top < HEIGHT)
			mlx_put_pixel(data->image.img,
				left, curr_y + top, generate_color(0, 0, 0, 255));
		curr_y++;
	}
}

void	draw_map2d(t_data *data)
{
	float	row;
	float	col;
	int		tile_s;
	char	*map_row;

	row = 0;
	tile_s = data->map_info.square_s;
	while (data->map_info.map_wt[(int)row])
	{
		col = 0;
		map_row = data->map_info.map_wt[(int)row];
		while (map_row[(int)col])
		{
			draw_square(generate_color(244, 206, 20, 255),
				row * tile_s, col * tile_s, data);
			if (map_row[(int)col] == '1')
				draw_square(generate_color(73, 94, 87, 255),
					row * tile_s, col * tile_s, data);
			col++;
		}
		row++;
	}
	draw_player(data->player._x, data->player._y, data);
}
