/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/09 21:43:46 by mbelouar         ###   ########.fr       */
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
	{
		//
	}
	else if (keycode == LROTATE)
	{
		//
	}
	return (0);
}

int handle_move(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);

	int	i;
	int	j;
	int	size = 10; // Adjust the size as needed
	int	half_size = size / 2;
	
	i = data->ray.player_x - half_size;
	while (i++ < data->ray.player_x + half_size)
	{
		j = data->ray.player_y - half_size;
		while (j++ < data->ray.player_y + half_size)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFFFFFF);
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
