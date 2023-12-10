/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:06:32 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 18:06:55 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	free_data(t_data *data)
{
	free(data->ray);
	// mlx_destroy_image(data->mlx_ptr, data->image.img);
	// mlx_close_window(data->mlx_ptr);
	free(data->mlx_ptr);
}
