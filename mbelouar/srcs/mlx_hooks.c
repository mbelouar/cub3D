/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/25 21:29:59 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_wall(t_data *data, float xtmp, float ytmp)
{
	int	S;

	S = data->map_info.square_S;
	if (data->map_info.map_wt[(int)data->player._y / S][(int)xtmp / S] == '1' ||
		data->map_info.map_wt[(int)ytmp / S][(int)data->player._x / S] == '1' ||
		data->map_info.map_wt[(int)ytmp / S][(int)xtmp / S] == '1' )
		return (0);
	return (1);
}

static void	check_and_draw(t_data *data)
{
	if (check_wall(data, data->x_tmp, data->y_tmp))
	{
		data->player._x = data->x_tmp;
		data->player._y = data->y_tmp;
		drawing(data);
	}
}

void	handle_moves(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->x_tmp = data->player._x;
	data->y_tmp = data->player._y;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
	{
		system("kill $(ps | grep afplay  | awk '{print $1}' | head -1)");
		mlx_close_window(data->mlx_ptr);
	}
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
	check_and_draw(data);
}

void	setup_rot_angle(t_data *data)
{
	data->ray->rayAngle = remainder(data->ray->rayAngle, 2 * M_PI);
	if (data->ray->rayAngle < 0)
		data->ray->rayAngle = (2 * M_PI) + data->ray->rayAngle;
}
