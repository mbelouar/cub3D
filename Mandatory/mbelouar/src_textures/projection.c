/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:19:52 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 17:46:26 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	generate3d_projection(t_data *data)
{
	int		i;
	int		wall_Height;
	int		wall_topPixel;
	int		wall_bottomPixel;
	float	corrected_dist;

	i = 0;
	while (i < WIDTH)
	{
		corrected_dist = data->ray[i].distance * cos(data->ray[i].rayAngle - data->r_angle);
		wall_Height = 13000 / corrected_dist;
		wall_topPixel = (HEIGHT / 2) - (wall_Height / 2);
		wall_bottomPixel = (HEIGHT / 2) + (wall_Height / 2);
		setup_texture(data, i);
		find_x_texture(data, i, data->hold.texture);
		draw_texture(data, i, wall_topPixel, wall_bottomPixel, wall_Height);
		i++;
	}
}

