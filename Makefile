# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 11:45:55 by vfurmane          #+#    #+#              #
#    Updated: 2021/06/23 12:48:37 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol
SRCS			= $(addprefix srcs/, algorithms.c check_args.c init.c main.c mlx_events.c my_mlx.c put.c route.c \
				  $(addprefix utils/, ft_strcmp.c))
OBJS			= $(SRCS:.c=.o)
INCL			= $(addprefix -I , includes minilibx-linux)
MLX_DIR			= minilibx-linux
MLX_FILE		= $(MLX_DIR)/libmlx_Linux.a
LIBS			= -L minilibx-linux -lmlx_Linux -lXext -lX11 -lm
CC				= clang
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

%.o:			%.c
				$(CC) $(CFLAGS) -c $< $(INCL) -o $@

all:			$(MLX_FILE) $(NAME)

$(MLX_FILE):
				git submodule init
				git submodule update
				make -C $(MLX_DIR)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ $(LIBS) -o $(NAME)

fast:			CFLAGS+= -O3
fast:			all

bonus:			$(MLX_FILE) all

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all mlx bonus clean fclean re
