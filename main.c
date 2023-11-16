/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:18:27 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/16 14:57:24 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	data;
	int		fd;

	fd = 0;
	if (ac != 2)
		print_and_exit_param();
	check_fd_map(&fd, av[1]);
	if (map_valid(&data, fd, av[1]))
	{
		ft_init_data(&data);
		mlx_loop_hook(data.mlx_ptr, handle_moves, &data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}


// #include "mlx.h"
// #include <stdio.h>

// typedef struct s_data
// {
//     void *mlx;
//     void *win;
//     double px;
//     double py;
//     int mapX;
//     int mapY;
//     int mapS;
//     int *map;
// } t_data;

// // Function prototype for draw_map2D
// void draw_map2D(t_data *data);

// void draw_player(t_data *data)
// {
//     double size = 5.0;

//     // Draw horizontal line
//     for (int i = -size; i <= size; i++)
//         mlx_pixel_put(data->mlx, data->win, (int)data->px + i, (int)data->py, 0xFFFF00);
//     // Draw vertical line
//     for (int i = -size; i <= size; i++)
//         mlx_pixel_put(data->mlx, data->win, (int)data->px, (int)data->py + i, 0xFFFF00);
// }

// int buttons(int keycode, t_data *data)
// {
//     double speed = 10.0;
//     if (keycode == 0)
//         data->px -= speed;
//     if (keycode == 2)
//         data->px += speed;
//     if (keycode == 13)
//         data->py -= speed;
//     if (keycode == 1)
//         data->py += speed;
//     mlx_clear_window(data->mlx, data->win);
//     draw_map2D(data);
//     draw_player(data);
//     return 0; // Change return type to int
// }

// void draw_map2D(t_data *data)
// {
// 	int x, y;
// 	int squareSize = data->mapS - 2; // Adjusted size to leave a border

// 	for (y = 0; y < data->mapY; y++)
// 	{
// 		for (x = 0; x < data->mapX; x++)
// 		{
// 			int index = y * data->mapX + x;
// 			if (data->map[index] == 1)
// 			{
// 				// Draw white square for value 1
// 				mlx_pixel_put(data->mlx, data->win, x * data->mapS + 1, y * data->mapS + 1, 0xFFFFFF);
// 				for (int i = 0; i < squareSize; i++)
// 				{
// 					for (int j = 0; j < squareSize; j++)
// 						mlx_pixel_put(data->mlx, data->win, x * data->mapS + i + 1, y * data->mapS + j + 1, 0xFFFFFF);
// 				}
// 			}
// 			else
// 				mlx_pixel_put(data->mlx, data->win, x * data->mapS + 1, y * data->mapS + 1, 0x000000);
// 		}
// 	}
// }


// int main(void)
// {
//     t_data data;

//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, 1024, 512, "Simple MinilibX Program");
//     data.px = 300;
//     data.py = 300;
//     data.mapX = 8;
//     data.mapY = 8;
//     data.mapS = 64;
//     data.map = (int[]){
//         1, 1, 1, 1, 1, 1, 1, 1,
//         1, 0, 1, 0, 0, 0, 0, 1,
//         1, 0, 1, 0, 0, 0, 0, 1,
//         1, 0, 1, 0, 0, 1, 0, 1,
//         1, 0, 0, 0, 0, 1, 0, 1,
//         1, 0, 0, 0, 0, 1, 0, 1,
//         1, 0, 0, 0, 0, 0, 0, 1,
//         1, 1, 1, 1, 1, 1, 1, 1};

//     mlx_key_hook(data.win, &buttons, &data); // Typecast buttons function
//     mlx_clear_window(data.mlx, data.win);
//     draw_map2D(&data);
//     draw_player(&data);
//     mlx_loop(data.mlx);

//     return 0;
// }


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

