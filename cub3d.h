/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:19:14 by mbelouar          #+#    #+#             */
/*   Updated: 2023/11/07 01:07:09 by mbelouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH		1400
# define HEIGHT		900
# define TITLE		"cub3D"

typedef struct e_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_data {
	t_image			image;
	void			*mlx_ptr;
	void			*win_ptr;
	double			scale;
	double			zoom;
	double			mouse_x;
	double			mouse_y;
}				t_data;

void	ft_init_data(t_data *data);
void	ft_init_image(t_data *data);



// bonjah
void	print_and_exit_param(void);
void	open_fd_check(int *fd, char *file);
int		close_window(t_data *data);

#endif
