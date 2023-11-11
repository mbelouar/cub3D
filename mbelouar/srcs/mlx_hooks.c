/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/10 18:12:47 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}

int	handle_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_close(data);
	else if (keycode == FORWARD)
		data->ray.player_y -= 10;
	else if (keycode == BACKWARDS)
		data->ray.player_y += 10;
	else if (keycode == LEFT)
		data->ray.player_x -= 10;
	else if (keycode == RIGHT)
		data->ray.player_x += 10;
	else if (keycode == RROTATE)
		data->r_angle += 0.09;
	else if (keycode == LROTATE)
		data->r_angle -= 0.09;
	return (0);
}

// int handle_move(t_data *data)
// {
// 	mlx_clear_window(data->mlx_ptr, data->win_ptr);

// 	int	i;
// 	int	j;
// 	int	size = 10; // Adjust the size as needed
// 	int	half_size = size / 2;

// 	i = data->ray.player_x - half_size;
// 	while (i++ < data->ray.player_x + half_size)
// 	{
// 		j = data->ray.player_y - half_size;
// 		while (j++ < data->ray.player_y + half_size)
// 			mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFFFFFF);
// 	}
// 	return (0);
// }


void draw_rotated_player(t_data *data, double angle)
{
    int i, j;
    int size = 10; // Adjust the size as needed
    int half_size = size / 2;

    for (i = -half_size; i < half_size; i++) {
        for (j = -half_size; j < half_size; j++) {
            // Apply rotation transformation to get new coordinates
            int new_x = cos(angle) * i - sin(angle) * j + data->ray.player_x;
            int new_y = sin(angle) * i + cos(angle) * j + data->ray.player_y;

            // Plot the point in the new rotated position
            plot_point(data, new_x, new_y, 0xFFFFFF);
        }
    }
}

// int handle_move(t_data *data)
// {
//     mlx_clear_window(data->mlx_ptr, data->win_ptr);

//     // Draw the rotated rectangle based on r_angle
//     draw_rotated_rectangle(data, data->r_angle);

//     mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, 0, 0);
//     return (0);
// }

int handle_move(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->image.img);

    // Create a new image
    data->image.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->image.addr = mlx_get_data_addr(data->image.img,
            &data->image.bits_per_pixel,
            &data->image.line_length,
            &data->image.endian);

    // Draw the rotated rectangle based on r_angle
    draw_rotated_player(data, data->r_angle);

    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, 0, 0);
    return (0);
}


// int	handle_move(t_data *data)
// {
// 	if (data->ray.forward == 1)
// 		// must move the player      (direction : +x and +y)
// 	if (data->ray.backwards == 1)
// 		// must move the player      (direction : -x and -y)
// 	if (data->ray.left == 1)
// 		// must move the player      (plane 2D  : -x and -y)
// 	if (data->ray.right == 1)
// 		// must move the player      (plane 2D  : +x and +y)
// 	if (data->ray.r_right == 1)
// 		// must rotate the player    (radian    : +pi/2)
// 	if (data->ray.r_left == 1)
// 		// must rotate the player    (radian    : -pi/2)
// 	return (1);
// }
