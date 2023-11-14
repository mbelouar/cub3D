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

void draw_player(double player_x, double player_y, t_data *data)
{
    double halfSize;
    double startX;
    double startY;
    double currentX;
    double currentY;

    halfSize = data->ray.player_size / 2.0;
    startX = player_x - halfSize;
    startY = player_y - halfSize;
    currentX = startX;
    while (currentX < startX + data->player.size)
    {
        currentY = startY;
        while (currentY < startY + data->player.size)
        {
            mlx_put_pixel(data->mlx.image, currentX, currentY, color);
            ++currentY;
        }
        ++currentX;
    }
}


// void draw_map2D(t_data *data)
// {
//     int x, y;
//     int squareSize = data->map_info.mapS - 2 ; // Adjusted size to leave a border

//     // color the entire window
//     // mlx_image_to_window(data->mlx, data->img, 0, 0);
//     for (y = 0; y < data->map_info.mapY; y++)
//     {
//         for (x = 0; x < data->map_info.mapX; x++)
//         {
//             int index = y * data->map_info.mapX + x;
//             if (data->map_info.map[index] == 1)
//             {
//                 // Draw white square for value 1
//                 mlx_put_pixel(data->image.img, x * data->map_info.mapS + 1, y * data->map_info.mapS + 1, generate_color(255, 15, 40));
//                 for (int i = 0; i <= squareSize; i++)
//                 {
//                     for (int j = 0; j <= squareSize; j++)
//                         mlx_put_pixel(data->image.img, x * data->map_info.mapS + i + 1, y * data->map_info.mapS + j + 1, generate_color(255, 15, 40));
//                 }
//             }
//             if (data->map_info.map[index] == 0)
//             {
//                 // Draw beige square for value 0
//                 mlx_put_pixel(data->image.img, x * data->map_info.mapS + 1, y * data->map_info.mapS + 1, 0x0000FF);
//                 for (int i = 0; i <= squareSize; i++)
//                 {
//                     for (int j = 0; j <= squareSize; j++)
//                         mlx_put_pixel(data->image.img, x * data->map_info.mapS + i + 1, y * data->map_info.mapS + j + 1, 0x0000FF);
//                 }
//             }
//             else
//                 mlx_put_pixel(data->image.img, x * data->map_info.mapS + 1, y * data->map_info.mapS + 1, generate_color(0, 0, 0));
//         }
//     }
//     draw_player(data);
// }

void draw_carre(int color, double top, double left, t_data *data)
{
    double currentX;
    double currentY;

    currentY = 0;
    while (currentY < data->map_info.mapS)
    {
        currentX = 0;
        while (currentX < data->map_info.mapS)
        {
            mlx_put_pixel(data->mlx.image, currentX + left, currentY + top, color);
            mlx_put_pixel(data->mlx.image, currentX + left, top, generate_color(0, 0, 0, 255));  //black
            currentX++;
        }
        mlx_put_pixel(data->mlx.image, left, currentY + top, generate_color(0, 0, 0, 255));  //black
        currentY++;
    }
}


void draw_map2D(t_data *data)
{
    double  row;
    double  col;
    int     carre_S;
    char    *mapRow;

    row = 0;
    carre_S = data->map_info.mapS;
    while (data->map_info.map[(int)row])
    {
        col = 0;
        mapRow = data->map_info.map[(int)row];
        while (mapRow[(int)col])
        {
            draw_carre(generate_color(241, 239, 239, 255), row * carre_S, col * carre_S, data);  //#F1EFEF off-white.
            if (mapRow[(int)col] == '1')
                draw_carre(generate_color(23, 107, 135, 255), row * carre_S, col * carre_S, data);  //#176B87  turquoise.
            col++;
        }
        row++;
    }
    drawPlayer(data->ray.plane_x, data->ray.player_y, data);
}


void drawing(t_data * data)
{
    draw_map2D(data);
}
