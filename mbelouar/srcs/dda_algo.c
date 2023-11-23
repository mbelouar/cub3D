/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:26:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/19 22:27:53 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void ft_dda(t_data *data, int xi, int yi, int xf, int yf)
{
    int steps;
    int dx;
    int i;
    int dy;
    double xinc;
    double yinc;
    double X;
    double Y;

    dx = xf - xi;
    dy = yf - yi;
    X = xi;
    Y = yi;
    i = 0;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    yinc = dy / (double)steps;
    xinc = dx / (double)steps;
    while (i <= steps)
    {
        mlx_put_pixel(data->image.img, round(X), round(Y), 0xFF0000FF);
        X += xinc;
        Y += yinc;
        i++;
    }
}

void	draw_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
        // printf("wall hit x ==> %f\n", data->ray[i].wallHit_x);
        // printf("wall hit y ==> %f\n", data->ray[i].wallHit_y);
		if (data->ray[i].wasHitVertical == 1)
			ft_dda(data, data->player._x, data->player._y, data->ray[i].wallHit_x, data->ray[i].wallHit_y);
		else
			ft_dda(data, data->player._x, data->player._y, data->ray[i].wallHit_x, data->ray[i].wallHit_y);
        i++;
	}
}

// void draw_rays(t_data *data)
// {
//     int i = 0;
//     while (i < WIDTH)
//     {
//         if (data->ray[i].wasHitVertical == 1)
//         {
//             if (data->hold.vertHit_x != 0 && data->hold.vertHit_y != 0)
//                 ft_dda(data, data->player._x + 4, data->player._y + 4, data->hold.vertHit_x, data->hold.vertHit_y);
//             else
//                 printf("Invalid vertical hit coordinates\n");
//         }
//         else
//         {
//             if (data->hold.horzHit_x != 0 && data->hold.horzHit_y != 0)
//                 ft_dda(data, data->player._x + 4, data->player._y + 4, data->hold.horzHit_x, data->hold.horzHit_y);
//             else
//                 printf("Invalid horizontal hit coordinates\n");
//         }
//         i++;
//     }
// }
