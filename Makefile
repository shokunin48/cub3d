# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 15:08:24 by ibellash          #+#    #+#              #
#    Updated: 2023/08/01 14:17:57 by ibellash         ###   ########.fr        #
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
		utils.c

NAME = cub3d

LIBFT = includes/libft/
MLX = mlx/

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
	@make -C $(MLX)
	@$(CC)$(CC_FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) includes/libft/libft.a $(MLX)libmlx.a

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all