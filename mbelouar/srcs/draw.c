/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:27:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/07 23:42:47 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	drawing(t_data *data)
{
	draw_floor(data);
	draw_roof(data);
	cast_all_rays(data);
	generate3D_projection(data);
	draw_map2d(data);
	draw_rays(data);
}
