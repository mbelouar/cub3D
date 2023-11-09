# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 23:15:39 by mbelouar          #+#    #+#              #
#    Updated: 2023/11/09 21:48:01 by mbelouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
RESET = \033[0m


NAME = cub3d

CC = cc

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

INCLUDE = -L libft -lft

SRC =		main.c \
			elalj/errors.c \
			mbelouar/srcs/ft_errors.c \
			mbelouar/srcs/init.c \
			mbelouar/srcs/mlx_hooks.c \
			mbelouar/srcs/colors.c \

OBJS := $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling cub3D...⏳$(RESET)"
	@echo "$(YELLOW)Linking...⏳$(RESET)"
	@make -C libft
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(INCLUDE)
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
