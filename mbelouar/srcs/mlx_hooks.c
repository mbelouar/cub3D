/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:25 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/07 17:23:29 by mbelouar         ###   ########.fr       */
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
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (0);
	}
	else if (keycode == FORWARD)
		data->ray.forward = 1;
	else if (keycode == BACKWARDS)
		data->ray.backwards = 1;
	else if (keycode == LEFT)
		data->ray.left = 1;
	else if (keycode == RIGHT)
		data->ray.right = 1;
	else if (keycode == RROTATE)
		data->ray.r_right = 1;
	else if (keycode == LROTATE)
		data->ray.r_left = 1;
	return (0);
}

int	handle_move(t_data *data)
{
	if (data->ray.forward == 1)
		// must move the player      (direction : +x and +y)
	if (data->ray.backwards == 1)
		// must move the player      (direction : -x and -y)
	if (data->ray.left == 1)
		// must move the player      (plane 2D  : -x and -y)
	if (data->ray.right == 1)
		// must move the player      (plane 2D  : +x and +y)
	if (data->ray.rot_right == 1)
		// must rotate the player    (radian    : +pi/2)
	if (data->ray.rot_left == 1)
		// must rotate the player    (radian    : -pi/2)
	return (1);
}
