/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:19:14 by mbelouar          #+#    #+#             */
/*   Updated: 2023/12/11 01:11:30 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# define FOV_ANGLE	60
# define SPEED_MOVE	1.50
# define WIDTH		1800
# define HEIGHT		900
# define TITLE		"cub3D"
# define INT_MAX	2147483647

typedef struct e_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_tex {
	mlx_texture_t	*tex_no;
	mlx_texture_t	*tex_so;
	mlx_texture_t	*tex_we;
	mlx_texture_t	*tex_ea;
}				t_tex;

typedef struct s_map {
	char	**map;
	char	**map_wt;
	int		map_size;
	int		map_width;
	int		map_height;
	int		square_s;
	char	snew_dir;
	int		snew_x;
	int		snew_y;
	char	**str;
	int		columns;
}				t_map;

typedef struct s_ray {
	float	ray_angle;
	float	wallhit_x;
	float	wallhit_y;
	float	distance;
	int		hit_vertical;
	int		wall_height;
	int		wall_top;
	int		wall_bottom;
}				t_ray;

typedef struct s_dda {
	int		steps;
	int		dx;
	int		dy;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
}				t_dda;

typedef struct s_projection {
	int		wall_height;
	int		wall_top;
	int		wall_bottom;
}				t_projection;

typedef struct s_holder {
	int				is_faceup;
	int				is_facedown;
	int				is_faceright;
	int				is_faceleft;
	int				foundhorz_hit;
	int				foundvert_hit;
	float			horzhit_x;
	float			horzhit_y;
	float			verthit_x;
	float			verthit_y;
	float			x_inter;
	float			y_inter;
	float			x_step;
	float			y_step;
	float			horznext_x;
	float			horznext_y;
	float			vertnext_x;
	float			vertnext_y;
	float			x_text;
	float			y_text;
	mlx_texture_t	*texture;
}				t_holder;

typedef struct s_dir {
	char	**no;
	char	**so;
	char	**we;
	char	**ea;
	char	**f;
	char	**c;
	char	**clr_f;
	int		floor[3];
	int		ceiling[3];
	char	**clr_c;
}				t_dir;

typedef struct s_player {
	float	_x;
	float	_y;
	float	p_size;
	float	fov;
}				t_player;

typedef struct s_data {
	t_image			image;
	t_player		player;
	t_ray			*ray;
	t_map			map_info;
	t_dir			dir;
	t_dda			dda;
	t_holder		hold;
	t_projection	project;
	t_tex			text;
	void			*mlx_ptr;
	void			*win_ptr;
	float			r_angle;
	float			x_tmp;
	float			y_tmp;
	int				c;
	int				mouse_x;
	int				mouse_y;
	int				tmp;
}				t_data;

// <========== RAYCASTING ==========>

// initialize functions
void	ft_init_data(t_data *data);
void	ft_init_player(t_data *data);
int		init_player_direction(t_data *data);

// error functions
void	err_msg(char *str, int fd);
void	print_and_exit_param(void);

// mlx hooks
void	handle_moves(void *param);

// colors
int		generate_color(int r, int g, int b, int a);
int		get_texture_color(float x, float y, mlx_texture_t *texture);

// moves
void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);

// drawing
void	drawing(t_data *data);

// raycast
void	cast_all_rays(t_data *data);
void	cast_ray(t_data *data, int i);
void	calculate_dis(t_data *data, int i);
void	vert_inter(t_data *data, float ray_angle);
void	horz_inter(t_data *data, float ray_angle);
void	setup_rot_angle(float *angle);
int		is_wall(t_data *data, float x, float y);

// projection
void	generate3d_projection(t_data *data);
void	draw_floor(t_data *data);
void	draw_roof(t_data *data);

// textures
void	draw_texture(t_data *data, int i);
void	find_x_texture(t_data *data, int i, mlx_texture_t *texture);
void	find_y_texture(t_data *data, int start);
void	setup_texture(t_data *data, int i);

// <========== PARSING ==========>

void	read_map(t_data *data, int fd);
int		map_valid(t_data *data, int fd, char *file);

// split
char	**ftt_split(char const *s, char c);
int		count_chars(char const *s, char delimiter, int lens);
int		count_words(char const *s, char delimiter);

// trim
char	*ftt_strtrim(char const *s1, char const *set);
int		check_end(char const *s, char const *set);
int		check_start(char const *s, char const *set);
int		check(char ch, char const *set);

// directions
void	check_many_directions(t_data *data);
void	print_err_directions(void);
void	init_directions(t_data *data);
void	ft_no(t_data *data);
void	ft_so(t_data *data);
void	ft_we(t_data *data);
void	ft_ea(t_data *data);
void	ft_f(t_data *data);
void	ft_c(t_data *data);
void	check_directions_needs(t_data *data);
void	check_no_needs(t_data *data);
void	check_so_needs(t_data *data);
void	check_we_needs(t_data *data);
void	check_ea_needs(t_data *data);
void	check_f_needs(t_data *data);
void	check_c_needs(t_data *data);
void	print_err_needs_directions(void);
void	check_colors(t_data *data);
void	check_f_c(t_data *data);
void	check_consecutive_semicolon_f(t_data *data);
void	valid_box_color_f(t_data *data);
void	valid_color_f(t_data *data);
void	check_c_c(t_data *data);
void	check_consecutive_semicolon_c(t_data *data);
void	valid_box_color_c(t_data *data);
void	valid_color_c(t_data *data);
void	init_maps(t_data *data);
void	init_map(t_data *data);
void	init_map_wt(t_data *data);
void	check_map(t_data *data);
void	found_tab_inside(t_data *data);
void	check_extension_map(char *file);
void	extension_err(void);
void	only_valid_characters(t_data *data);
void	check_surr_by_walls(t_data *data);
void	not_surr_err(void);
void	check_around_spaces(t_data *data);
void	start_checking_around_spaces(char **str);
void	ch_inside_map(char **str, int i, int j);
void	around_spaces_err(void);
void	check_if_double_directions(t_data *data);
void	double_directions_err(void);
void	non_directions_err(void);
void	check_if_play_can_go_bg(t_data *data);
int		found_last_0(char *line);
void	init_f_array(t_data *data);
void	init_c_array(t_data *data);
void	check_long_map(t_data *data);

// errors
void	check_fd_map(int *fd, char *file);
void	print_and_exit_param(void);
void	err_empty_map(void);
void	found_semicolon_err(void);
void	err_semicolons(void);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

// gnl
char	*get_next_line(int fd);
char	*ft_read(char *all, int fd);
char	*cut(char *str);
char	*copy_to_xyata(char *str);

// libft_needed
char	*ftt_strcpy(char *dst, char *src);
char	*ftt_strjoin(char *s1, char *s2);
char	*ftt_strchr(const char *s, int c);
size_t	ftt_strlen(const char *s);

// free
void	ft_str_free(char **s);
int		__strchrr(char *line, char c);
void	ft_close(void	*param);

#endif
