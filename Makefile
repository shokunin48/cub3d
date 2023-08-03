# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 15:08:24 by ibellash          #+#    #+#              #
#    Updated: 2023/08/03 16:41:25 by dsas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		exit.c \
		init_map.c \
		map_errors.c \
		map.c \
		pic_utils.c \
		split_utils.c \
		color_trgb.c \
		fill_map.c \
		utils.c \
		textures.c \
		raycasting.c \
		raycasting2.c \
		keys.c \
		keys2.c \
		move.c

NAME = cub3d

LIBFT = includes/libft/
MLX = mlx/
LIBS	= -lm -lmlx -framework OpenGL -framework AppKit
SRCS_DIR = srcs/

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc -o3

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c includes/cub3d.h
	@mkdir -p $(OBJS_DIR)
	@gcc $(CC_FLAGS) -O3 -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	#@make -C $(MLX)
	#@$(CC) -o $(NAME) $(CC_FLAGS) -I $(OBJECTS_PREFIXED) includes/libft/libft.a $(LIBS)
	@$(CC)$(CC_FLAGS) -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) includes/libft/libft.a 

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all