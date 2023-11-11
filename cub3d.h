/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:19:14 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/10 17:15:56 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define LROTATE 123
# define RROTATE 124
# define FORWARD 13
# define BACKWARDS 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define SPEED_MOVE 0.01
# define WIDTH		800
# define HEIGHT		600
# define TITLE		"cub3D"

typedef struct e_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_map {
	char			**map;
	int				map_width;
	int				map_height;
	char			snew_dir;
    int             snew_x;
    int             snew_y;
}				t_map;

typedef struct s_ray {
    // Player position
    double player_x;
    double player_y;

    // Direction vector
    double direction_x;
    double direction_y;

    // 2D camera plane
    double plane_x;
    double plane_y;

    // Camera plane increment for calculating ray direction
    double camera;

    // Ray direction vector
    double ray_vect_x;
    double ray_vect_y;

    // Map grid position
    int x_map;
    int y_map;

    // Length of ray from current position to next x or y-side
    double x_dist;
    double y_dist;

    // Length of ray from one x or y-side to next x or y-side
    double delta_dist_x;
    double delta_dist_y;

    // Perpendicular distance from the camera to the wall, used for wall height calculation
    double wall_dist;

    // Step direction (either +1 or -1) in x and y
    int step_x;
    int step_y;

    // Flag indicating whether a wall is touched
    int touch;

    // Flag indicating which face of the wall was touched (0 for x-side, 1 for y-side) NS or EW
    int face_touched;

    // Size of each step (pixel) for drawing the walls
    double step_size;

    // Constant value for converting degrees to radians
    double const_rad;

    // Height of the line to be drawn on the screen
    int wall_height;

    // Start and end points for drawing the wall slice on the screen
    int draw_start;
    int draw_end;

    // Relative position of the wall hit, used for texture mapping
    double wall_x;

    // Movement flags for player control
    int forward;
    int backwards;
    int left;
    int right;
    int r_left;
    int r_right;
}				t_ray;

typedef struct s_data {
	t_image			image;
	t_ray			ray;
	t_map			map_info;
	void			*mlx_ptr;
	void			*win_ptr;
	double			width;
	double			height;
    double          r_angle;
}				t_data;

// initialize functions
void	ft_init_data(t_data *data);
void	ft_init_image(t_data *data);
void	ft_init_player(t_data *data);
int     init_player_direction(t_data *data);

// error functions
void	err_msg(char *str, int fd);
void	print_and_exit_param(void);
void	open_fd_check(int *fd, char *file);

// mlx hooks
int		ft_close(t_data *data);
int		esc_handle(int keycode, t_data *data);
int     handle_hook(int keycode, t_data *data);
int     handle_move(t_data *data);

// colors
void	plot_point(t_data *data, int x, int y, int color);

// moves
void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);
bool    valid_move(t_data *data, double x, double y);

#endif
