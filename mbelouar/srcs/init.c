/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:20:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/07 17:26:59 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_init_player(t_data *data)
{

}

void	ft_init_image(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->image.img)
		err_msg("Image creation failed\n", 2);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel,
			&data->image.line_length,
			&data->image.endian);
	mlx_key_hook(data->win_ptr, &esc_handle, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close, data);
	ft_init_player(&data);
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		err_msg("Mlx initialization failed\n", 2);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!(data->win_ptr))
		err_msg("Window creation failed\n", 2);
	ft_init_image(data);
}
