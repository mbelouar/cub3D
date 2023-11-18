/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/18 16:43:49 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	handle_moves(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx_ptr);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
		ft_move_up(data);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
		ft_move_down(data);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
		ft_move_left(data);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
		ft_move_right(data);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT))
		data->r_angle += 0.05;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
		data->r_angle -= 0.05;
	drawing(data);
}

// void setup_rot_angle(t_data *data)
// {
// 	if (data->r_angle < 0)
// 		data->r_angle += (2 * M_PI);
// 	if (data->r_angle > (2 * M_PI))
// 		data->r_angle -= (2 * M_PI);
// }
