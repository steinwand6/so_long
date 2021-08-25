# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tishigak <tishigak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 03:09:50 by tishigak          #+#    #+#              #
#    Updated: 2021/08/17 14:09:06 by tishigak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= gcc
CFLAGS	= -Wall -Werror -Wextra
MLXFLAGS	= -lm -lXext -lX11
MLX			= minilibx-linux
SRCS		= main.c read_map.c utils.c
HEADERPATH	= -I ./

OBJS	= $(SRCS:.c=.o)
OBJSB	= $(SRCSB:.c=.o)
ifdef WITH_BONUS
ALL_OBJS = $(OBJS) $(OBJSB)
else
ALL_OBJS = $(OBJS)
endif

all:	$(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJSB)
	@make -C libft clean
	@make -C $(MLX) clean

$(MLX) :
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX)

fclean:	clean
	rm -f $(NAME)
	@make -C libft fclean
	@make -C $(MLX) clean
	rm -f $(MLX)/libmlx_Linux.a

re:	fclean all

#bonus:
#	@$(MAKE) WITH_BONUS=1 $(NAME)

$(NAME):	$(MLX) $(ALL_OBJS)
	@make -C ./libft
	@make -C ./$(MLX)
	gcc -o $(NAME) $(ALL_OBJS) ./libft/libft.a ./$(MLX)/libmlx_Linux.a ${MLXFLAGS}

.PHONY:	all clean fclean re bonus

vpath %.c srcs
