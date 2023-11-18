/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:25:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/18 18:25:46 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_ray(t_data *data, int ray_angle)
{
}

void	cast_rays(t_data *data)
{
	int		i = 0;
	int		column_id = 0;
	double	ray_angle = data->r_angle - (FOV_ANGLE / 2);

	while (i < WIDTH)
	{
		// draw the ray
		ray_angle += FOV_ANGLE / WIDTH;
		column_id++;
		i++;
	}
}
