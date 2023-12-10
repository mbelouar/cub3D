/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:18:27 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/11 00:19:59 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_close(void	*param)
{
	t_data	*data;

	data = (t_data *)param;
	system("kill $(ps | grep afplay  | awk '{print $1}' | head -1)");
	mlx_close_window(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;
	int		f_pid;

	fd = 0;
	if (ac != 2)
		print_and_exit_param();
	check_fd_map(&fd, av[1]);
	if (map_valid(&data, fd, av[1]))
	{
		f_pid = fork();
		if (f_pid == 0)
		{
			system("afplay /Users/$USER/Desktop/cub3D/Bonus/songs/y.mp3");
			exit (0);
		}
		ft_init_data(&data);
		mlx_loop_hook(data.mlx_ptr, handle_moves, &data);
		mlx_close_hook(data.mlx_ptr, ft_close, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
