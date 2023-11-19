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
    float xinc;
    float yinc;
    float X;
    float Y;

    dx = xf - xi;
    dy = yf - yi;
    X = xi;
    Y = yi;
    i = 0;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    yinc = dy / (float)steps;
    xinc = dx / (float)steps;
    while (i <= steps)
    {
        mlx_put_pixel(data->image.img, round(X), round(Y), 0xFF0000FF);
        X += xinc;
        Y += yinc;
        i++;
    }
}
