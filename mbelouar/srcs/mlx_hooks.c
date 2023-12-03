/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/03 23:05:15 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_wall(t_data *data, float xtmp, float ytmp)
{
	int	tile_s;

	tile_s = data->map_info.square_S;
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

// void mouse_hook(int curr_x, void *param)
// {
// 	// static int old_x;
// 	// static int	i;
// 	t_data *data;

// 	data = (t_data *)param;

// 	printf("curr_x : %d\n", curr_x);

// 	// Print additional information for debugging
// 	printf("data pointer: %p\n", (void *)data);

// 	// Rest of mouse_hook logic...
// }


void	mouse_hook(int curr_x, void *param)
{
	static int	old_x;
	static int	i;
	t_data		*data;

	data = (t_data *)param;
	printf("curr x ==> %d\n", curr_x);
	if (old_x == 0)
		old_x = curr_x;
	if (i++ == 1)
	{
		if (old_x > curr_x)
			data->r_angle -= 0.08;
		if (old_x < curr_x)
			data->r_angle += 0.08;
		i = 0;
		old_x = curr_x;
	}
	setup_rot_angle(data);
}


// must modify this function to normalize any angle i give it
void	setup_rot_angle(t_data *data)
{
	data->ray->rayAngle = remainder(data->ray->rayAngle, 2 * M_PI);
	data->r_angle = remainder(data->r_angle, 2 * M_PI);
	if (data->ray->rayAngle < 0)
		data->ray->rayAngle = (2 * M_PI) + data->ray->rayAngle;
	if (data->r_angle < 0)
		data->r_angle = (2 * M_PI) + data->r_angle;
}
