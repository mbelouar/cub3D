/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:19:14 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/25 23:58:21 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define FOV_ANGLE	60 * (M_PI / 180)
# define SPEED_MOVE	1.50
# define WIDTH		2200
# define HEIGHT		1000
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
	int		square_S;
	char	snew_dir;
	int		snew_x;
	int		snew_y;
	char	**str;
	int		columns;
}				t_map;

typedef struct s_ray {
	float	rayAngle;
	float	wallHit_x;
	float	wallHit_y;
	float	distance;
	int		wasHitVertical;
}				t_ray;

typedef struct s_dda {
	int		steps;
	int		dx;
	int		dy;
	float	Xinc;
	float	Yinc;
	float	X;
	float	Y;
}				t_dda;

typedef struct s_projection {
	float	dist_projec;
	float	projWall_height;
	int		wall_Height;
	int		wall_topPixel;
	int		wall_bottomPixel;
}				t_projection;

typedef struct s_holder {
	int		is_FaceUp;
	int		is_FaceDown;
	int		is_FaceRight;
	int		is_FaceLeft;
	int		foundHorz_hit;
	int		foundVert_hit;
	float	horzHit_x;
	float	horzHit_y;
	float	vertHit_x;
	float	vertHit_y;
	float	x_inter;
	float	y_inter;
	float	x_step;
	float	y_step;
	float	HorzNext_x;
	float	HorzNext_y;
	float	VertNext_x;
	float	VertNext_y;
}				t_holder;

typedef struct s_dir {
	char	**NO;
	char	**SO;
	char	**WE;
	char	**EA;
	char	**F;
	char	**clr_f;
	int		floor[3];
	int		ceiling[3];
	char	**C;
	char	**clr_c;
}				t_dir;

typedef struct s_player {
	float	_x;
	float	_y;
	float	p_size;
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
	t_tex			tex;
	void			*mlx_ptr;
	void			*win_ptr;
	float			r_angle;
	float			x_tmp;
	float			y_tmp;
	int				c;
	// unsigned int    *Color_buffer;
}				t_data;

// <========== RAYCASTING ==========>

// initialize functions
void	ft_init_data(t_data *data);
void	ft_init_image(t_data *data);
void	ft_init_player(t_data *data);
int		init_player_direction(t_data *data);

// error functions
void	err_msg(char *str, int fd);
void	print_and_exit_param(void);
void	open_fd_check(int *fd, char *file);

// mlx hooks
void	handle_moves(void *param);
//int		ft_close(t_data *data);
int		esc_handle(int keycode, t_data *data);

// colors
int		generate_color(int r, int g, int b, int a);

// moves
void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);

// drawing
void	drawing(t_data * data);
void	draw_map2D(t_data *data);
void	draw_carre(int color, float top, float left, t_data *data);
void	draw_player(float player_x, float player_y, t_data *data);
void	draw_rays(t_data *data);

// raycast
void	castAll_rays(t_data *data);
void	cast_ray(t_data *data, int i);
void	calculate_dis(t_data *data, int i);
void	vert_inter(t_data *data, float ray_angle);
void	horz_inter(t_data *data, float ray_angle);
void	ft_dda(t_data *data, int xi, int yi, int xf, int yf);
void	setup_rot_angle(t_data *data);
int		is_wall(t_data *data, float x, float y);

// projection
void	clearColor_buffer(t_data *data, unsigned int color);
void	generate3D_projection(t_data *data);
void	draw_floor(t_data *data);
void	draw_roof(t_data *data);

// <========== PARSING ==========>

void	read_map(t_data *data, int fd);
int		map_valid(t_data *data, int fd, char *file);

//split
char	**ftt_split(char const *s, char c);
int		count_chars(char const *s, char delimiter, int lens);
int		count_words(char const *s, char delimiter);

//trim
char	*ftt_strtrim(char const *s1, char const *set);
int		check_end(char const *s, char const *set);
int		check_start(char const *s, char const *set);
int		check(char ch, char const *set);

//directions
void	check_many_directions(t_data *data);
void	print_err_directions();
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
void	print_err_needs_directions();
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
void	check_if_float_directions(t_data *data);
void	float_directions_err(void);
void	non_directions_err(void);
void	check_if_play_can_go_bg(t_data *data);
int		found_last_0(char *line);
void	init_f_array(t_data *data);
void	init_c_array(t_data *data);

//errors
void	check_fd_map(int *fd, char *file);
void	print_and_exit_param(void);
void	err_empty_map(void);
void	found_semicolon_err(void);
void	err_semicolons(void);

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337

//gnl
char	*get_next_line(int fd);
char	*ft_read(char *all, int fd);
char	*cut(char *str);
char	*copy_to_xyata(char *str);

//libft_needed
char	*ftt_strcpy(char *dst, char *src);
char	*ftt_strjoin(char *s1, char *s2);
char	*ftt_strchr(const char *s, int c);
size_t	ftt_strlen(const char *s);

// free
void	ft_str_free(char **s);
int		__strchrr(char *line, char c);

#endif
#endif

