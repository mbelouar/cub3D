# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 23:15:39 by mbelouar          #+#    #+#              #
#    Updated: 2023/11/13 17:11:56 by mbelouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RESET = \033[0m


NAME = cub3d

IMLX = -I /Users/mbelouar/MLX42/include/MLX42

GLFW = -I include -lglfw -L"/goinfre/$(USER)/homebrew/opt/glfw/lib/"

CC = cc

MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

AR_MLX = /Users/mbelouar/MLX42/build/libmlx42.a

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

INCLUDE = -L libft -lft

SRC =		main.c \
			elalj/errors.c \
			mbelouar/srcs/ft_errors.c \
			mbelouar/srcs/init.c \
			mbelouar/srcs/mlx_hooks.c \
			mbelouar/srcs/colors.c \
			mbelouar/srcs/draw.c \
			mbelouar/srcs/moves.c \

OBJS := $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< $(IMLX) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling cub3D...⏳$(RESET)"
	@echo "$(YELLOW)Linking...⏳$(RESET)"
	@make -C libft
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(AR_MLX) $(IMLX) $(GLFW) -o $(NAME) $(OBJS) $(INCLUDE)
	@echo "$(GREEN)Compilation completed ✅$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)Deleting obj_files$(RESET)"
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleting obj_files + ./cub3D$(RESET)"
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
