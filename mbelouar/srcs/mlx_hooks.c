/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/09 18:31:03 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}

// int	handle_hook(int keycode, t_data *data)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		exit (0);
// 	}
// 	else if (keycode == FORWARD)
// 		data->ray.forward = 1;
// 	else if (keycode == BACKWARDS)
// 		data->ray.backwards = 1;
// 	else if (keycode == LEFT)
// 		data->ray.left = 1;
// 	else if (keycode == RIGHT)
// 		data->ray.right = 1;
// 	return (0);
// }

void ft_rotate(t_data *data, double angle_change)
{
    data->rotation_angle += angle_change;
    // You may need to update direction and plane vectors based on the new rotation angle
    // Example:
    data->ray.direction_x = cos(data->rotation_angle);
    data->ray.direction_y = sin(data->rotation_angle);
    // Update the 2D camera plane as well if needed
    data->ray.plane_x = -sin(data->rotation_angle);
    data->ray.plane_y = cos(data->rotation_angle);
}

int handle_hook(int keycode, t_data *data)
{
    if (keycode == ESC) // ASCII code for Esc key
        ft_close(data);
    else if (keycode == 126) // ASCII code for up arrow key
        data->ray.player_y -= 10;
    else if (keycode == 125) // ASCII code for down arrow key
        data->ray.player_y += 10;
    else if (keycode == 123) // ASCII code for left arrow key
        data->ray.player_x -= 10;
    else if (keycode == 124) // ASCII code for right arrow key
        data->ray.player_x += 10;
    else if (keycode == 'a')
	{
		// must rotate the player    (radian    : +pi/2)
		ft_rotate(data, M_PI / 2.0);
	}
	else if (keycode == 'd')
	{
		// must rotate the player    (radian    : -pi/2)
		ft_rotate(data, -M_PI / 2.0);
	}

    return (0);
}

int handle_move(t_data *data)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr);

    int size = 10; // Adjust the size as needed
    int half_size = size / 2;

    int rotation_center_x = data->ray.player_x; // Rotation center x-coordinate
    int rotation_center_y = data->ray.player_y; // Rotation center y-coordinate

    for (int i = data->ray.player_x - half_size; i < data->ray.player_x + half_size; i++) {
        for (int j = data->ray.player_y - half_size; j < data->ray.player_y + half_size; j++) {
            // Calculate rotated coordinates
            int rotated_x = rotation_center_x + (i - rotation_center_x) * cos(data->rotation_angle) - (j - rotation_center_y) * sin(data->rotation_angle);
            int rotated_y = rotation_center_y + (i - rotation_center_x) * sin(data->rotation_angle) + (j - rotation_center_y) * cos(data->rotation_angle);

            mlx_pixel_put(data->mlx_ptr, data->win_ptr, rotated_x, rotated_y, 0xFFFFFF);
        }
    }

    return (0);
}


// Function to move the player
// void ft_move(t_data *data, int direction)
// {
//     // Move the player in the direction vector
//     data->ray.player_x += direction * data->ray.direction_x * 5; // Adjust the movement speed as needed
//     data->ray.player_y += direction * data->ray.direction_y * 5;
// }

// // Function to strafe the player
// void ft_strafe(t_data *data, int strafe_direction)
// {
//     // Move the player perpendicular to the direction vector (2D camera plane movement)
//     data->ray.player_x += strafe_direction * data->ray.plane_x * 5; // Adjust the movement speed as needed
//     data->ray.player_y += strafe_direction * data->ray.plane_y * 5;
// }


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
