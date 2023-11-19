/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/19 23:06:06 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int check_wall(t_data *data, double xtmp, double ytmp)
{
	int	S;

	S = data->map_info.square_S;
	if (data->map_info.map_wt[(int)data->ray.player_x / S][(int)ytmp / S] == '1' ||
		data->map_info.map_wt[(int)xtmp / S][(int)data->ray.player_y / S] == '1' ||
		data->map_info.map_wt[(int)xtmp / S][(int)ytmp / S] == '1' )
		return (0);
	return (1);
}

void	handle_moves(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->x_tmp = data->ray.player_x;
	data->y_tmp = data->ray.player_y;
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
	if (check_wall(data, data->x_tmp, data->y_tmp))
	{
		data->ray.player_x = data->x_tmp;
		data->ray.player_y = data->y_tmp;
		drawing(data);
	}
}

double setup_rot_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}
