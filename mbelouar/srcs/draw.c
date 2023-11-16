/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:27:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/16 16:34:33 by mbelouar         ###   ########.fr       */
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
    while (currentX < startX + data->ray.player_size)
    {
        currentY = startY;
        while (currentY < startY + data->ray.player_size)
        {
            mlx_put_pixel(data->image.img, currentX, currentY, generate_color(255, 255, 0, 255));
            ++currentY;
        }
        ++currentX;
    }
}

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
            // Check if the coordinates are within the bounds of the image
            if (currentX + left < WIDTH && currentY + top < HEIGHT) {
                mlx_put_pixel(data->image.img, currentX + left, currentY + top, color);
            }

            // Check if the coordinates are within the bounds of the image
            if (currentX + left < WIDTH && top < HEIGHT) {
                mlx_put_pixel(data->image.img, currentX + left, top, generate_color(0, 0, 0, 255));  //black
            }
            currentX++;
        }
        // Check if the coordinates are within the bounds of the image
        if (left < WIDTH && currentY + top < HEIGHT) {
            mlx_put_pixel(data->image.img, left, currentY + top, generate_color(0, 0, 0, 255));  //black
        }
        currentY++;
    }
}


// void draw_carre(int color, double top, double left, t_data *data)
// {
//     double currentX;
//     double currentY;

//     currentY = 0;
//     while (currentY < data->map_info.mapS)
//     {
//         currentX = 0;
//         while (currentX < data->map_info.mapS)
//         {
//             mlx_put_pixel(data->image.img, currentX + left, currentY + top, color);
//             mlx_put_pixel(data->image.img, currentX + left, top, generate_color(0, 0, 0, 255));  //black
//             currentX++;
//         }
//         mlx_put_pixel(data->image.img, left, currentY + top, generate_color(0, 0, 0, 255));  //black
//         currentY++;
//     }
// }


void draw_map2D(t_data *data)
{
    double  row;
    double  col;
    int     carre_S;
    char    *mapRow;

    row = 0;
    carre_S = data->map_info.mapS;
    while (data->map_info.map_wt[(int)row])
    {
        col = 0;
        mapRow = data->map_info.map_wt[(int)row];
        while (mapRow[(int)col])
        {
            draw_carre(generate_color(241, 239, 239, 255), row * carre_S, col * carre_S, data);  //#F1EFEF off-white.
            if (mapRow[(int)col] == '1')
                draw_carre(generate_color(23, 107, 135, 255), row * carre_S, col * carre_S, data);  //#176B87  turquoise.
            col++;
        }
        row++;
    }
    draw_player(data->ray.plane_x, data->ray.player_y, data);
}


void drawing(t_data *data)
{
    draw_map2D(data);
}
