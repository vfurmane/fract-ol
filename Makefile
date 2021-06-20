# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 11:45:55 by vfurmane          #+#    #+#              #
#    Updated: 2021/06/20 17:06:36 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol
SRCS			= $(addprefix srcs/, check_args.c main.c put.c \
				  $(addprefix utils/, ft_strcmp.c))
OBJS			= $(SRCS:.c=.o)
INCL			= $(addprefix -I , includes minilibx-linux)
MLX_DIR			= minilibx-linux
MLX_FILE		= $(MLX_DIR)/libmlx_Linux.a
LIBS			= -L minilibx-linux -lmlx_Linux -lXext -lX11 -lm
CC				= clang
CFLAGS			= -Wall -Wextra -Werror -ggdb
RM				= rm -f

%.o:			%.c
				$(CC) $(CFLAGS) -c $< $(INCL) -o $@

all:			CFLAGS+= -fsanitize=address
all:			$(MLX_FILE) $(NAME)

$(MLX_FILE):
				git submodule init
				git submodule update
				make -C $(MLX_DIR)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ -o $(NAME)

bonus:			$(MLX_FILE) all

nosanitize:		$(MLX_FILE) $(NAME)

clean:
				$(RM) $(OBJS)
				make -C $(MLX_DIR) clean

fclean:			clean
				$(RM) $(NAME)
				make -C $(MLX_DIR) fclean

re:				fclean all

.PHONY:			all mlx bonus nosanitize clean fclean re
