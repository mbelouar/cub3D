/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:45:54 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/13 21:50:45 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	ft_dda(t_data *data, int Xi, int Yi, int Xf, int Yf)
{
	int	i;

	data->dda.dx = Xf - Xi;
	data->dda.dy = Yf - Yi;
	if (abs(data->dda.dx) > abs(data->dda.dy))
		data->dda.steps = abs(data->dda.dx);
	else
		data->dda.steps = abs(data->dda.dy);
	data->dda.x_inc = data->dda.dx / (float)data->dda.steps;
	data->dda.y_inc = data->dda.dy / (float)data->dda.steps;
	data->dda.x = Xi;
	data->dda.y = Yi;
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

void	draw_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		if (data->ray[i].hit_vertical == 1)
			ft_dda(data, data->player._x, data->player._y,
				data->ray[i].wallhit_x, data->ray[i].wallhit_y);
		else
			ft_dda(data, data->player._x, data->player._y,
				data->ray[i].wallhit_x, data->ray[i].wallhit_y);
		i++;
	}
}
