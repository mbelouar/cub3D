/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:20:40 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/07 17:26:59 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_init_player(t_data *data)
{
	data->ray.player_x = data->map.snew_x + 0.5;
	data->ray.player_y = data->map.snew_y + 0.5;
	data->ray.direction_x = 0;
	data->ray.direction_y = 0;
	data->ray.plane_x = 0;
	data->ray.plane_y = 0.78; // 45 degree
	data->ray.step_size = 0.1;
	data->ray.const_rad = M_PI / 45;
	data->ray.forward = 0;
	data->ray.backwards = 0;
	data->ray.left = 0;
	data->ray.right = 0;
	data->ray.rot_left = 0;
	data->ray.rot_right = 0;
	initialize_player_direction(data);
	return (0);
}

void	ft_init_image(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->image.img)
		err_msg("Image creation failed\n", 2);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel,
			&data->image.line_length,
			&data->image.endian);
	mlx_key_hook(data->win_ptr, &esc_handle, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close, data);
	ft_init_player(&data);
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		err_msg("Mlx initialization failed\n", 2);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!(data->win_ptr))
		err_msg("Window creation failed\n", 2);
	ft_init_image(data);
}

int initialize_player_direction(t_data *data)
{
    double initial_rotation_angle;

	initial_rotation_angle = 0.0;
    // Check the initial snew direction and set the corresponding rotation angle
    if (data->map.snew_dir == 'E')
        initial_rotation_angle = M_PI / 2;  // Rotate 90 degrees for East direction
    else if (data->map.snew_dir == 'S')
        initial_rotation_angle = M_PI;      // Rotate 180 degrees for South direction
    else if (data->map.snew_dir == 'W')
        initial_rotation_angle = (3 * M_PI) / 2; // Rotate 270 degrees for West direction

    // Apply the initial rotation to set player direction
    // rotate the player with the initial_rotate_angle

    return (0);
}
