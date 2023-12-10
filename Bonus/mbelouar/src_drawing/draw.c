/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:27:51 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/11 00:16:26 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	drawing(t_data *data)
{
	draw_floor(data);
	draw_roof(data);
	cast_all_rays(data);
	generate3d_projection(data);
	draw_map2d(data);
}
