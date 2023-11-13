/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/13 17:50:52 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// int	handle_hook(int keycode, t_data *data)
// {
// 	if (keycode == 53)
// 		ft_close(data);
// 	else if (keycode == KEY_W)
// 		data->ray.player_y -= 10;
// 	else if (keycode == KEY_S)
// 		data->ray.player_y += 10;
// 	else if (keycode == KEY_A)
// 		data->ray.player_x -= 10;
// 	else if (keycode == KEY_D)
// 		data->ray.player_x += 10;
// 	else if (keycode == RIGHT_ROTATE)
// 		data->r_angle += 0.09;
// 	else if (keycode == LEFT_ROTATE)
// 		data->r_angle -= 0.09;
// 	return (0);
// }

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
		data->r_angle -= 0.05;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
		data->r_angle += 0.05;
	// setup_rot_angle(data);
	// drawing(data);
}

// void setup_rot_angle(t_data_t *data)
// {
// 	if (data->r_angle < 0)
// 		data->r_angle += (2 * M_PI);
// 	if (data->r_angle > (2 * M_PI))
// 		data->r_angle -= (2 * M_PI);
// }
