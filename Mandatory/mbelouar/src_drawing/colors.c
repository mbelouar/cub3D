/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:51:43 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 23:41:12 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	generate_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_texture_color(float x, float y, mlx_texture_t *texture)
{
	int	pixel_index;
	int	r;
	int	g;
	int	b;
	int	a;

	if (x < 0 || y < 0 || (uint32_t)x >= texture->width
		|| (uint32_t)y >= texture->height)
		return (generate_color(0, 0, 0, 255));
	pixel_index = ((int)y * (int)texture->width + (int)x)
		* (int)texture->bytes_per_pixel;
	r = texture->pixels[pixel_index + 0];
	g = texture->pixels[pixel_index + 1];
	b = texture->pixels[pixel_index + 2];
	a = texture->pixels[pixel_index + 3];
	return (generate_color(r, g, b, a));
}
