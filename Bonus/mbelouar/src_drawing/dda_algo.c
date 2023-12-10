/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:26:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 23:22:01 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	ft_dda(t_data *data, int xi, int yi, int xf, int yf)
{
	int	i;

	data->dda.dx = xf - xi;
	data->dda.dy = yf - yi;
	if (abs(data->dda.dx) > abs(data->dda.dy))
		data->dda.steps = abs(data->dda.dx);
	else
		data->dda.steps = abs(data->dda.dy);
	data->dda.x_inc = data->dda.dx / (float)data->dda.steps;
	data->dda.y_inc = data->dda.dy / (float)data->dda.steps;
	data->dda.x = xi;
	data->dda.y = yi;
	i = 0;
	while (i <= data->dda.steps)
	{
		mlx_put_pixel(data->image.img, round(data->dda.x),
			round(data->dda.y), generate_color(255, 0, 0, 255));
		data->dda.x += data->dda.x_inc;
		data->dda.y += data->dda.y_inc;
		i++;
	}
}
