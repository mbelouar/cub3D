/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/17 19:59:45 by mbelouar         ###   ########.fr       */
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
int checkwall(t_data *data, double xtmp, double ytmp){

	if (data->map_info.map_wt[(int)data->ray.player_x / 64][(int)ytmp / 64] == '1' ||
	data->map_info.map_wt[(int)xtmp / 64][(int)data->ray.player_y / 64] == '1' ||
		data->map_info.map_wt[(int)xtmp / 64][(int)ytmp / 64] == '1' )
		return 0;
	return 1;
}
void	handle_moves(void *param)
{
	t_data	*data;
	data = (t_data *)param;
	double x_tmp = data->ray.player_x;
	double y_tmp = data->ray.player_y;

	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx_ptr);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
		ft_move_up(data, x_tmp, y_tmp);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
		ft_move_down(data, x_tmp, y_tmp);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
		ft_move_left(data, x_tmp, y_tmp);
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
		ft_move_right(data, x_tmp, y_tmp);
	if (checkwall(data, x_tmp, y_tmp)){
		data->ray.player_x = x_tmp;
		data->ray.player_y = y_tmp;
		drawing(data);
	}
	// if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT))
	// 	data->r_angle += 0.05;
	// if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
	// 	data->r_angle -= 0.05;
	// if (check_wall())
}

// void	handle_moves(void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// 	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
// 		mlx_close_window(data->mlx_ptr);
// 	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
// 		data->ray.player_x -= 5.0;
// 	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
// 		data->ray.player_x += 5.0;
// 	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
// 		data->ray.player_y -= 5.0;
// 	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
// 		data->ray.player_y += 5.0;
// 	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_LEFT))
// 		data->r_angle -= 0.05;
// 	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
// 		data->r_angle += 0.05;
// 	setup_rot_angle(data);
// 	drawing(data);
// }

// void setup_rot_angle(t_data *data)
// {
// 	if (data->r_angle < 0)
// 		data->r_angle += (2 * M_PI);
// 	if (data->r_angle > (2 * M_PI))
// 		data->r_angle -= (2 * M_PI);
// }
