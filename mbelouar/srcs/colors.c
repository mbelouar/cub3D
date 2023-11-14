/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:51:43 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/13 17:25:03 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/**
 * This function plots a single point in the window with the specified color.
 * It takes in the x and y coordinates of the point, as well as the color to
 * use for the pixel. The function calculates the memory address of the pixel
 * in the window using the WIDTH and HEIGHT of the window, and then sets the
 * color of the pixel to the specified value.
 */
void	plot_point(t_data *data, int x, int y, int color)
{
	char	*addr;

	addr = data->image.addr + (y * data->image.line_length + x
			* (data->image.bits_per_pixel / 8));
	*(unsigned int *)addr = (unsigned int)color;
}

int generate_color(int red, int green, int blue, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
