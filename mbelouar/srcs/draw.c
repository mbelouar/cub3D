/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:27:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/13 17:24:53 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void draw_player(t_data *data)
{
    double size = 5.0;

    // Draw horizontal line
    for (int i = -size; i <= size; i++)
        mlx_put_pixel(data->image.img, (int)data->ray.player_x + i, (int)data->ray.player_y, 0xFFFF00FF);
    // Draw vertical line
    for (int i = -size; i <= size; i++)
        mlx_put_pixel(data->image.img, (int)data->ray.player_x, (int)data->ray.player_y + i, 0xFFFF00FF);
}

void draw_map2D(t_data *data)
{
    int x, y;
    int squareSize = data->map_info.mapS - 2 ; // Adjusted size to leave a border

    // color the entire window
    // mlx_image_to_window(data->mlx, data->img, 0, 0);
    for (y = 0; y < data->map_info.mapY; y++)
    {
        for (x = 0; x < data->map_info.mapX; x++)
        {
            int index = y * data->map_info.mapX + x;
            if (data->map_info.map[index] == 1)
            {
                // Draw white square for value 1
                mlx_put_pixel(data->image.img, x * data->map_info.mapS + 1, y * data->map_info.mapS + 1, generate_color(255, 15, 40));
                for (int i = 0; i <= squareSize; i++)
                {
                    for (int j = 0; j <= squareSize; j++)
                        mlx_put_pixel(data->image.img, x * data->map_info.mapS + i + 1, y * data->map_info.mapS + j + 1, generate_color(255, 15, 40));
                }
            }
            if (data->map_info.map[index] == 0)
            {
                // Draw beige square for value 0
                mlx_put_pixel(data->image.img, x * data->map_info.mapS + 1, y * data->map_info.mapS + 1, 0x0000FF);
                for (int i = 0; i <= squareSize; i++)
                {
                    for (int j = 0; j <= squareSize; j++)
                        mlx_put_pixel(data->image.img, x * data->map_info.mapS + i + 1, y * data->map_info.mapS + j + 1, 0x0000FF);
                }
            }
            else
                mlx_put_pixel(data->image.img, x * data->map_info.mapS + 1, y * data->map_info.mapS + 1, generate_color(0, 0, 0));
        }
    }
    draw_player(data);
}

void drawing(t_data * data)
{
    draw_map2D(data);
}
