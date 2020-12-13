# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/02 00:23:52 by qmalcom           #+#    #+#              #
#    Updated: 2020/10/15 01:31:06 by qmalcom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3d
MAKE_LIBFT = cd ./ft_libft && make
MAKE_MINILIBX = cd ./minilibx && make
CFILES =	./sources/main.c \
			./sources/ft_get_next_line.c \
			./sources/ft_get_next_line_utils.c \
			./sources/ft_structure.c \
			./sources/ft_file_open.c \
			./sources/ft_parser_get_type.c \
			./sources/ft_parser.c \
			./sources/ft_get_map_darr.c \
			./sources/ft_basic_functions.c \
			./sources/ft_map_check_prep.c \
			./sources/ft_map_check.c \
			./sources/ft_mlx_basic.c \
			./sources/ft_mlx_func_1.c \
			./sources/ft_mlx_func_2.c \
			./sources/ft_mlx_hooks_1.c \
			./sources/ft_mlx_hooks_2.c \
			./sources/ft_get_textures.c \
			./sources/ft_raycast_func.c \
			./sources/ft_raycast_textr.c \
			./sources/ft_raycast_sprite_1.c \
			./sources/ft_raycast_sprite_2.c \
			./sources/ft_screenshot.c

OFILES = $(CFILES:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OFILES) ./includes/cub3d.h
	@$(MAKE_LIBFT) bonus
	@$(MAKE_MINILIBX)
	#@$(CC) $(CFLAGS) -o $(NAME) $(OFILES) -Lft_libft -lft -L/usr/X11/lib -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -I/usr/X11/include -Iincludes
	@$(CC) $(CFLAGS) -o $(NAME) $(OFILES) -Lft_libft -lft -Lminilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd -I/usr/X11/include -Iincludes
	@echo "cub3d successfully created!"

%.o: ./sources/%.c
	@$(CC) $(CFLAGS) $<

.PHONY: clean
clean:
	$(MAKE_LIBFT) clean
	$(MAKE_MINILIBX) clean
	@rm -rf $(OFILES)
	@rm -f first_frame.bmp

.PHONY: fclean
fclean: clean
	@$(MAKE_LIBFT) fclean
	@$()
	@rm -rf $(NAME)

.PHONY: re
re: fclean all