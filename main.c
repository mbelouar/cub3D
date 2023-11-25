/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:18:27 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/25 17:03:36 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	data;
	pid_t	f_pid;
	int		fd;

	fd = 0;
	if (ac != 2)
		print_and_exit_param();
	check_fd_map(&fd, av[1]);
	if (map_valid(&data, fd, av[1]))
	{
		f_pid = fork();
		if (f_pid == 0)
		{
			system("afplay /Users/mbelouar/Desktop/cub3D/songs/ikambi.mp3");
			exit (0);
		}
		ft_init_data(&data);
		mlx_loop_hook(data.mlx_ptr, handle_moves, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
