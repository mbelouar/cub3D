/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:18:27 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/07 17:26:24 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	(void)av;
	t_data	data;

	if (ac != 2)
		print_and_exit_param();
	ft_init_data(&data);
	mlx_hook(data.win_ptr, 17, 0, &ft_close, &data);
	mlx_hook(data.win_ptr, 2, 0, &handle_hook, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_move, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
