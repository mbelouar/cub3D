/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:49:26 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/25 16:40:37 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_player(float player_x, float player_y, t_data *data)
{
	float	startX;
	float	startY;
	float	currentX;
	float	currentY;

	startX = player_x - data->player.p_size / 2.0;
	startY = player_y - data->player.p_size / 2.0;
	currentX = startX;
	while (currentX < startX + data->player.p_size)
	{
		currentY = startY;
		while (currentY < startY + data->player.p_size)
		{
			mlx_put_pixel(data->image.img,
				currentX, currentY, generate_color(0, 0, 0, 255));
			++currentY;
		}
		++currentX;
	}
}

void	draw_square(int color, float top, float left, t_data *data)
{
	float	currentX;
	float	currentY;

	currentY = 0;
	while (currentY < data->map_info.square_S)
	{
		currentX = 0;
		while (currentX < data->map_info.square_S)
		{
			if (currentX + left < WIDTH && currentY + top < HEIGHT)
				mlx_put_pixel(data->image.img,
					currentX + left, currentY + top, color);
			if (currentX + left < WIDTH && top < HEIGHT)
				mlx_put_pixel(data->image.img,
					currentX + left, top, generate_color(0, 0, 0, 255));
			currentX++;
		}
		if (left < WIDTH && currentY + top < HEIGHT)
			mlx_put_pixel(data->image.img,
				left, currentY + top, generate_color(0, 0, 0, 255));
		currentY++;
	}
}

void	draw_map2D(t_data *data)
{
	float	row;
	float	col;
	int		square_S;
	char	*mapRow;

	row = 0;
	square_S = data->map_info.square_S;
	while (data->map_info.map_wt[(int)row])
	{
		col = 0;
		mapRow = data->map_info.map_wt[(int)row];
		while (mapRow[(int)col])
		{
			draw_square(generate_color(224, 244, 255, 255),
				row * square_S, col * square_S, data);
			if (mapRow[(int)col] == '1')
				draw_square(generate_color(24, 111, 101, 255),
					row * square_S, col * square_S, data);
			col++;
		}
		row++;
	}
	draw_player(data->player._x, data->player._y, data);
}

void	draw_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		if (data->ray[i].wasHitVertical == 1)
			ft_dda(data, data->player._x, data->player._y,
				data->ray[i].wallHit_x, data->ray[i].wallHit_y);
		else
			ft_dda(data, data->player._x, data->player._y,
				data->ray[i].wallHit_x, data->ray[i].wallHit_y);
		i++;
	}
}
