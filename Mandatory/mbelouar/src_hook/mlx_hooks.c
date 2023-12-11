/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/10 23:51:31 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_wall(t_data *data, float xtmp, float ytmp)
{
	int	tile_s;

	tile_s = data->map_info.square_s;
	if (data->map_info.map_wt[(int)data->player._y / tile_s]
		[(int)xtmp / tile_s] == '1'
		|| data->map_info.map_wt[(int)ytmp / tile_s]
		[(int)data->player._x / tile_s] == '1'
		|| data->map_info.map_wt[(int)ytmp / tile_s]
		[(int)xtmp / tile_s] == '1' )
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
		data->r_angle -= 0.08;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_RIGHT))
		data->r_angle += 0.08;
	setup_rot_angle(&data->r_angle);
	check_and_draw(data);
}

void	setup_rot_angle(float *angle)
{
	*angle = remainder(*angle, 2 * M_PI);
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
}
