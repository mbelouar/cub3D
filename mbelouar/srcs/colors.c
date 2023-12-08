/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:51:43 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/08 01:49:58 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	generate_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int get_texture_color(int x_coord, int y_coord, mlx_texture_t *texture)
{
	if (x_coord < 0 || y_coord < 0 || (uint32_t)x_coord >= texture->width
		|| (uint32_t)y_coord >= texture->height)
		return (generate_color(0, 0, 0, 255));

	// Calculate the starting index of the pixel in the 1D pixel array
	int pixel_index = (y_coord * texture->width + x_coord) * texture->bytes_per_pixel;

	// Use bitwise operations to construct the color value
	int r = texture->pixels[pixel_index + 0];
	int g = texture->pixels[pixel_index + 1];
	int b = texture->pixels[pixel_index + 2];
	int a = texture->pixels[pixel_index + 3];

	return (generate_color(r, g, b, a));
}
