/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:20:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/20 17:09:00 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_init_player(t_data *data)
{
	data->player._x = data->map_info.snew_x * data->map_info.square_S + (data->map_info.square_S / 2);
	data->player._y = data->map_info.snew_y * data->map_info.square_S + (data->map_info.square_S / 2);
	data->player.p_size = 8;
	init_player_direction(data);
}

void	ft_init_map(t_data *data)
{
	data->map_info.square_S = 64;
	data->map_info.map_height = 0;
	data->map_info.map_width = 0;
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, 0);
	if (!(data->mlx_ptr))
		err_msg("Mlx initialization failed\n", 2);
	if (!(data->image.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT)))
    {
        mlx_close_window(data->mlx_ptr);
		err_msg("Mlx creation image failed\n", 2);
    }
	mlx_image_to_window(data->mlx_ptr, data->image.img, 0, 0);
	ft_init_map(data);
	ft_init_player(data);
	data->ray = (t_ray *)malloc(sizeof(t_ray) * WIDTH);
}

int init_player_direction(t_data *data)
{
	double	initial_rotation_angle;

	initial_rotation_angle = 0.0;
	if (data->map_info.snew_dir == 'E')
		initial_rotation_angle = 0;
	else if (data->map_info.snew_dir == 'W')
		initial_rotation_angle = M_PI;
	else if (data->map_info.snew_dir == 'S')
		initial_rotation_angle = M_PI / 2;
	else if (data->map_info.snew_dir == 'N')
		initial_rotation_angle = (3 * M_PI) / 2;
	data->r_angle = initial_rotation_angle;
	return (0);
}
