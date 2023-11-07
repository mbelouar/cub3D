# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 23:15:39 by mbelouar          #+#    #+#              #
#    Updated: 2023/11/07 01:09:54 by mbelouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

SRC = mbelouar/srcs/main.c

NAME = cub3d
CC = cc
FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
INCLUDE = -L libft -lft
OBJS := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@echo "$(RED)Compiling cub3D...$(RESET)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDE)
	@echo "$(GREEN)Compilation complete$(RESET)"

clean:
	@$(RM) $(OBJS)
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
