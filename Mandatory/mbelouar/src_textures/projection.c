/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:19:52 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/11 00:08:03 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	generate3d_projection(t_data *data)
{
	int		i;
	float	corrected_dist;

	i = 0;
	while (i < WIDTH)
	{
		corrected_dist = data->ray[i].distance
			* cos(data->ray[i].ray_angle - data->r_angle);
		data->project.wall_height = 13000 / corrected_dist;
		data->project.wall_top = (HEIGHT / 2)
			- (data->project.wall_height / 2);
		data->project.wall_bottom = (HEIGHT / 2)
			+ (data->project.wall_height / 2);
		setup_texture(data, i);
		find_x_texture(data, i, data->hold.texture);
		draw_texture(data, i);
		i++;
	}
}
