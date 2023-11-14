/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:20:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/13 17:23:36 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_init_player(t_data *data)
{
	// after parse the map
	// data->ray.player_x = data->map_info.snew_x + 0.5;
	// data->ray.player_y = data->map_info.snew_y + 0.5;
	data->r_angle = 0.0;
	data->ray.player_x = WIDTH / 2;
	data->ray.player_y = HEIGHT / 2;
	data->ray.player_size = 8;
	data->ray.direction_x = 0.0;
	data->ray.direction_y = 0.0;
	data->ray.plane_x = 0.0;
	data->ray.plane_y = 0.0; // 45 degree
	data->ray.step_size = 0.1;
	init_player_direction(data);
}

void	ft_init_map(t_data *data)
{
	data->map_info.mapS = 64;
	data->map_info.map_height = 0;
	data->map_info.map_width = 0;
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (!(data->mlx_ptr))
		err_msg("Mlx initialization failed\n", 2);
	data->win_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!(data->win_ptr))
		err_msg("Window creation failed\n", 2);
	mlx_image_to_window(data->mlx_ptr, data->image.img, 0, 0);
	ft_init_player(data);
	ft_init_map(data);
}

int init_player_direction(t_data *data)
{
	double	initial_rotation_angle;

	initial_rotation_angle = 0.0;
	// Check the initial snew direction and set the corresponding rotation angle
	if (data->map_info.snew_dir == 'N')
		initial_rotation_angle = 0;
	else if (data->map_info.snew_dir == 'S')
		initial_rotation_angle = M_PI;      // Rotate 180 degrees for South direction
	else if (data->map_info.snew_dir == 'E')
		initial_rotation_angle = M_PI / 2;  // Rotate 90 degrees for East direction
	else if (data->map_info.snew_dir == 'W')
		initial_rotation_angle = (3 * M_PI) / 2; // Rotate 270 degrees for West direction
	data->r_angle = initial_rotation_angle;

	return (0);
}
