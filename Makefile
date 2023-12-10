# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 23:15:39 by mbelouar          #+#    #+#              #
#    Updated: 2023/12/10 00:08:15 by mbelouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

B_NAME = cub3D_bonus

all: $(NAME)

$(NAME): 
	@make -s -C Mandatory

bonus: $(B_NAME)

$(B_NAME):
	@make -s -C bonus

clean:
	@make clean -s -C Mandatory
	@make clean -s -C Bonus

fclean:
	@make fclean -s -C Mandatory
	@make fclean -s -C Bonus
re: fclean all

.PHONY: all clean fclean re