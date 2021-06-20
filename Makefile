# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 11:45:55 by vfurmane          #+#    #+#              #
#    Updated: 2021/06/20 17:01:01 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
SRCS		= $(addprefix srcs/, check_args.c main.c put.c \
			  $(addprefix utils/, ft_strcmp.c))
OBJS		= $(SRCS:.c=.o)
INCL		= $(addprefix -I , includes minilibx-linux)
MLX_DIR		= minilibx-linux
LIBS		= -L minilibx-linux -lmlx_Linux -lXext -lX11 -lm
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -ggdb
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

all:		CFLAGS+= -fsanitize=address
all:		mlx $(NAME)

mlx:
			git submodule init
			git submodule update
			make -C $(MLX_DIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $(NAME)

bonus:		all

nosanitize:	$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all mlx bonus nosanitize clean fclean re
