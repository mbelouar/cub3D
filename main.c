/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:18:27 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/07 01:16:01 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *data)
{
	(void)data;	//we need it later
	//we need to free all after exit..
	exit (0);
	return (0);
}
void	ft_init_image(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->image.img)
		ft_putstr_fd("Image creation failed\n", 2);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel,
			&data->image.line_length,
			&data->image.endian);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		ft_putstr_fd("Mlx initialization failed\n", 2);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!(data->win_ptr))
		ft_putstr_fd("Window creation failed\n", 2);
	ft_init_image(data);
}

int main(int ac, char **av)
{
	(void)av;
	t_data	data;
	int			fd;

	fd = 0;
	if (ac == 2)
	{
		//open_fd_check(&fd, av[1]);	//for check ila kan dak map already kayn ->> hadi tal men ba3d wndiroha
		ft_init_data(&data);
		mlx_loop(data.mlx_ptr);
	}
	else
		print_and_exit_param(); //error d map beli makynx
	return (0);
}
