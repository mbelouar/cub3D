# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelouar <mbelouar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 23:55:22 by mbelouar          #+#    #+#              #
#    Updated: 2023/10/23 17:03:13 by mbelouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  ft_isalnum.c ft_isalpha.c ft_strcpy.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_bzero.c ft_putchar.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_itoa.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_split_lst.c ft_strsep.c ft_strtok.c
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a
AR		= ar -rcs
CC		= cc
CFLAGS = -Wall -Werror -Wextra
RM 		= rm -f
BONUS_O	= ${BONUS:.c=.o}

all:	${NAME}

.c.o:
	@$(CC) -c $< -o $@
${NAME}:	${OBJS}
			@${AR} ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
