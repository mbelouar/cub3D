/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:18:27 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/10 17:38:35 by mbelouar         ###   ########.fr       */
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


// #include "mlx.h"
// #include <stdlib.h>
// #include <math.h>

// #define PI 3.14159265358979323846

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     int x;
//     int y;
//     int angle;
// } t_vars;

// void draw_rectangle(t_vars *vars)
// {
//     int i;
//     int j;
//     int new_x, new_y;

//     i = 0;
//     while (i < 100)
//     {
//         j = 0;
//         while (j < 50)
//         {
//             // Rotate each pixel based on the angle
//             new_x = cos(vars->angle * PI / 180) * (i - 50) - sin(vars->angle * PI / 180) * (j - 25) + 50 + vars->x;
//             new_y = sin(vars->angle * PI / 180) * (i - 50) + cos(vars->angle * PI / 180) * (j - 25) + 25 + vars->y;

//             mlx_pixel_put(vars->mlx, vars->win, new_x, new_y, 0xFFFFFF); // White color
//             j++;
//         }
//         i++;
//     }
// }

// int key_hook(int keycode, t_vars *vars)
// {
//     if (keycode == 53) // ESC key to exit
//         exit(0);
//     else if (keycode == 123) // Left arrow key
//         vars->x -= 5;
//     else if (keycode == 124) // Right arrow key
//         vars->x += 5;
//     else if (keycode == 125) // Down arrow key
//         vars->y += 5;
//     else if (keycode == 126) // Up arrow key
//         vars->y -= 5;
//     else if (keycode == 0) // 'A' key
//         vars->angle -= 5;
//     else if (keycode == 2) // 'D' key
//         vars->angle += 5;

//     mlx_clear_window(vars->mlx, vars->win);
//     draw_rectangle(vars);
//     return (0);
// }

// int main(void)
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 800, 600, "Rectangle Movement and Rotation");
//     vars.x = 100;
//     vars.y = 100;
//     vars.angle = 0;

//     mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);

//     mlx_loop(vars.mlx);
//     return (0);
// }

