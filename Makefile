# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 23:15:39 by mbelouar          #+#    #+#              #
#    Updated: 2023/12/13 21:48:38 by mbelouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
WHITE = \033[1;37m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RESET = \033[0m

NAME = cub3D

B_NAME = cub3D_bonus

IMLX = -I /Users/$(USER)/MLX42/include/MLX42
# GLFW = -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
GLFW = -I include -lglfw -L"/goinfre/$(USER)/homebrew/opt/glfw/lib/"

CC = cc

MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

AR_MLX = /Users/$(USER)/MLX42/build/libmlx42.a

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

INCLUDE = -L Mandatory/libft -lft

B_INCLUDE = -L Bonus/libft -lft

SRC =		Mandatory/main.c\
			Mandatory/elalj/errors.c\
			Mandatory/elalj/read_map.c\
			Mandatory/elalj/parsing.c\
			Mandatory/elalj/ft_split.c\
			Mandatory/elalj/ftt_strtrim.c\
			Mandatory/elalj/gnl/get_next_line.c\
			Mandatory/elalj/gnl/get_next_line_utils.c\
			Mandatory/elalj/directions/check_directions.c\
			Mandatory/elalj/directions/init_directions.c\
			Mandatory/elalj/directions/err_directions.c\
			Mandatory/elalj/directions/check_needs_directions.c\
			Mandatory/elalj/directions/check_color_f.c\
			Mandatory/elalj/directions/check_color_c.c\
			Mandatory/elalj/map/check_map.c\
			Mandatory/elalj/map/check_map_2.c\
			Mandatory/elalj/map/map_casses.c\
			Mandatory/elalj/map/errors_map.c\
			Mandatory/mbelouar/src_utils/ft_errors.c\
			Mandatory/mbelouar/src_utils/init.c\
			Mandatory/mbelouar/src_drawing/colors.c\
			Mandatory/mbelouar/src_drawing/draw.c\
			Mandatory/mbelouar/src_hook/mlx_hooks.c\
			Mandatory/mbelouar/src_hook/moves.c\
			Mandatory/mbelouar/src_raycasting/raycast.c\
			Mandatory/mbelouar/src_raycasting/horz_inter.c\
			Mandatory/mbelouar/src_raycasting/vert_inter.c\
			Mandatory/mbelouar/src_textures/projection.c\
			Mandatory/mbelouar/src_textures/textures_coord.c\
			Mandatory/mbelouar/src_textures/roof_floor.c\

B_SRC =	Bonus/main_bonus.c\
			Bonus/elalj/errors.c\
			Bonus/elalj/read_map.c\
			Bonus/elalj/parsing.c\
			Bonus/elalj/ft_split.c\
			Bonus/elalj/ftt_strtrim.c\
			Bonus/elalj/gnl/get_next_line.c\
			Bonus/elalj/gnl/get_next_line_utils.c\
			Bonus/elalj/directions/check_directions.c\
			Bonus/elalj/directions/init_directions.c\
			Bonus/elalj/directions/err_directions.c\
			Bonus/elalj/directions/check_needs_directions.c\
			Bonus/elalj/directions/check_color_f.c\
			Bonus/elalj/directions/check_color_c.c\
			Bonus/elalj/map/check_map.c\
			Bonus/elalj/map/check_map_2.c\
			Bonus/elalj/map/map_casses.c\
			Bonus/elalj/map/errors_map.c\
			Bonus/mbelouar/src_utils/ft_errors.c\
			Bonus/mbelouar/src_utils/init.c\
			Bonus/mbelouar/src_drawing/colors.c\
			Bonus/mbelouar/src_drawing/draw.c\
			Bonus/mbelouar/src_drawing/draw_utils.c\
			Bonus/mbelouar/src_hook/mlx_hooks.c\
			Bonus/mbelouar/src_hook/moves.c\
			Bonus/mbelouar/src_raycasting/raycast.c\
			Bonus/mbelouar/src_raycasting/horz_inter.c\
			Bonus/mbelouar/src_raycasting/vert_inter.c\
			Bonus/mbelouar/src_textures/projection.c\
			Bonus/mbelouar/src_textures/textures_coord.c\
			Bonus/mbelouar/src_textures/roof_floor.c\
			Bonus/mbelouar/src_rays/draw_rays.c\

OBJS := $(SRC:.c=.o)

B_OBJS := $(B_SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< $(IMLX) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)...⏳$(RESET)"
	@echo "$(YELLOW)Linking...⏳$(RESET)"
	@make -s -C Mandatory/libft
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(AR_MLX) $(IMLX) $(GLFW) -o $(NAME) $(OBJS) $(INCLUDE)
	@echo "$(GREEN)Compilation completed ✅$(RESET)"
	@echo "$(GREEN) $$CUB3D $(END)"

bonus: $(B_NAME)

$(B_NAME): $(B_OBJS)
	@echo "$(YELLOW)Compiling $(B_NAME)...⏳$(RESET)"
	@echo "$(YELLOW)Linking...⏳$(RESET)"
	@make -s -C Bonus/libft
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(AR_MLX) $(IMLX) $(GLFW) -o $(B_NAME) $(B_OBJS) $(B_INCLUDE)
	@echo "$(GREEN)Compilation completed ✅$(RESET)"
	@echo "$(GREEN) $$CUB3D $(END)"

clean:
	@$(RM) $(OBJS) $(B_OBJS)
	@echo "$(RED)Deleting obj_files$(RESET)"
	@make clean -s -C Mandatory/libft
	@make clean -s -C Bonus/libft

fclean: clean
	@$(RM) $(NAME) $(B_NAME)
	@echo "$(RED)Deleting obj_files + ./exec_file$(RESET)"
	@make fclean -s -C Mandatory/libft
	@make fclean -s -C Bonus/libft

re: fclean all

.PHONY: all clean fclean re bonus

define CUB3D

	═══════════  ██████╗██╗   ██╗██████╗ ██████╗ ██████╗  ═══════════
	══════════  ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗  ═══════════	 $(RED)
	══════════  ██║     ██║   ██║███⭐️██╔ █████╔╝██║  ██║  ═══════════
	══════════  ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║  ═══════════	$(YELLOW)
	══════════  ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝  ═══════════
	═══════════  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝  ═══════════
			cub3d By: $(WHITE)mbelouar && moelalj $(RESET)

		CONTROLE PANEL 🎮: ═══╗
		                      ╚══﹥ ROTATING KEYS: ◀️ rotate left / ▶️ rotate right.
		                      ║
		                      ╚══﹥ MOVES KEYS: 🅰 move left / 🆂 move backword / 🅳 move right / 🆆 move forword.
				      ║
				      ╚══﹥ EXIT KEY: 🇪 EXIT.
endef
export CUB3D
