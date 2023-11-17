/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:20:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/17 17:31:35 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_init_player(t_data *data)
{
	// after parse the map
	printf("x_player : %d\n", data->map_info.snew_x);
	printf("y_player : %d\n", data->map_info.snew_y);
	data->ray.player_x = data->map_info.snew_x * data->map_info.square_S + (data->map_info.square_S / 2);
	data->ray.player_y = data->map_info.snew_y * data->map_info.square_S + (data->map_info.square_S / 2);
	printf("x : %f\n", data->ray.player_x);
	printf("y : %f\n", data->ray.player_y);
	// data->r_angle = 0.0;
	data->ray.player_size = 10;
	data->ray.direction_x = 0.0;
	data->ray.direction_y = 0.0;
	data->ray.plane_x = 0.0;
	data->ray.plane_y = 0.0;
	data->ray.step_size = 0.1;
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
	data->mlx_ptr = mlx_init(WIDTH, HEIGHT, TITLE, true);
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
}

int init_player_direction(t_data *data)
{
	double	initial_rotation_angle;

	initial_rotation_angle = 0.0;
	// printf("dir : %c\n", data->map_info.snew_dir);
	if (data->map_info.snew_dir == 'N')
		initial_rotation_angle = 0;
	else if (data->map_info.snew_dir == 'S')
		initial_rotation_angle = M_PI;
	else if (data->map_info.snew_dir == 'E')
		initial_rotation_angle = M_PI / 2;
	else if (data->map_info.snew_dir == 'W')
		initial_rotation_angle = (3 * M_PI) / 2;
	// printf("initial rotation angle : %f\n\n", initial_rotation_angle);
	data->r_angle = initial_rotation_angle;
	return (0);
}
