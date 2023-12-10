/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:26:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 00:05:14 by mbelouar         ###   ########.fr       */
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
	data->dda.Xinc = data->dda.dx / (float)data->dda.steps;
	data->dda.Yinc = data->dda.dy / (float)data->dda.steps;
	data->dda.X = Xi;
	data->dda.Y = Yi;
	i = 0;
	while (i <= data->dda.steps)
	{
		mlx_put_pixel(data->image.img, round(data->dda.X),
			round(data->dda.Y), generate_color(255, 0, 0, 255));
		data->dda.X += data->dda.Xinc;
		data->dda.Y += data->dda.Yinc;
		i++;
	}
}
