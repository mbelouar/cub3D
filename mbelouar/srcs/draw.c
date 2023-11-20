/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:27:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/20 21:13:53 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void draw_player(double player_x, double player_y, t_data *data)
{
    double startX;
    double startY;
    double currentX;
    double currentY;

    startX = player_y - data->player.p_size / 2;
    startY = player_x - data->player.p_size / 2;
    currentX = startX;
    while (currentX < startX + data->player.p_size)
    {
        currentY = startY;
        while (currentY < startY + data->player.p_size)
        {
            mlx_put_pixel(data->image.img, currentX, currentY, generate_color(0, 0,0 , 255));
            currentY++;
        }
        currentX++;
    }
}

// void draw_player(double player_x, double player_y, t_data *data)
// {
//     double radius = data->player.p_size / 2.0;
//     double centerX = player_y;
//     double centerY = player_x;

//     for (int i = (int)(centerX - radius); i <= (int)(centerX + radius); ++i)
//     {
//         for (int j = (int)(centerY - radius); j <= (int)(centerY + radius); ++j)
//         {
//             double distance = sqrt((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY));
//             if (distance <= radius)
//             {
//                 // Inside the circle, set pixel color
//                 mlx_put_pixel(data->image.img, i, j, generate_color(0, 0, 0, 255));
//             }
//         }
//     }
// }


void draw_square(int color, double top, double left, t_data *data)
{
    double currentX;
    double currentY;

    currentY = 0;
    while (currentY < data->map_info.square_S)
    {
        currentX = 0;
        while (currentX < data->map_info.square_S)
        {
            // Check if the coordinates are within the bounds of the image
            if (currentX + left < WIDTH && currentY + top < HEIGHT)
                mlx_put_pixel(data->image.img, currentX + left, currentY + top, color);
            // Check if the coordinates are within the bounds of the image
            if (currentX + left < WIDTH && top < HEIGHT)
                mlx_put_pixel(data->image.img, currentX + left, top, generate_color(0, 0, 0, 255));  //black
            currentX++;
        }
        // Check if the coordinates are within the bounds of the image
        if (left < WIDTH && currentY + top < HEIGHT)
            mlx_put_pixel(data->image.img, left, currentY + top, generate_color(0, 0, 0, 255));  //black
        currentY++;
    }
}

void draw_map2D(t_data *data)
{
    double  row;
    double  col;
    int     square_S;
    char    *mapRow;

    row = 0;
    square_S = data->map_info.square_S;
    while (data->map_info.map_wt[(int)row])
    {
        col = 0;
        mapRow = data->map_info.map_wt[(int)row];
        while (mapRow[(int)col])
        {
            draw_square(generate_color(224, 244, 255, 255), row * square_S, col * square_S, data);  //#F1EFEF off-white.
            if (mapRow[(int)col] == '1')
                draw_square(generate_color(22, 72, 99, 255), row * square_S, col * square_S, data);  //#176B87  turquoise.
            col++;
        }
        row++;
    }
    draw_player(data->player._x, data->player._y, data);
}


void drawing(t_data *data)
{
    draw_map2D(data);
    castAll_rays(data);
    draw_rays(data);
}
