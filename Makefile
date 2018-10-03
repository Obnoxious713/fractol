# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 12:08:05 by jfleisch          #+#    #+#              #
#    Updated: 2018/09/05 12:08:06 by jfleisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Werror -Wextra -g

CC = gcc

NORM = norminette -R CheckForbiddenSourceHeader

SRC = main.c \
		color.c \
		fractals.c \
		thread.c \
		gfx.c \
		hc_julia.c \
		hooks.c \
		image.c \
		julia_mouse.c \
		mouse_hooks.c \
		toggle_keys.c

OBJ = $(addprefix $(ODIR),$(SRC:.c=.o))

LIBFT = ./libft/libft.a
LIBFTINC = -I./libft
LINK_FT = -L./libft -lft -L./libft/printf -lftprintf -L./libft/complex -lftcomplex
FT_NAME = libft

MLX = ./libgfx/minilibx/libmlx.a
MLXINC = -I./libgfx/minilibx
LINK_MLX = -L./libgfx/minilibx -lmlx -framework OpenGL -framework AppKit
MLX_NAME = minilibx

LIBGFX = ./libgfx/libgfx.a
LIBGFXINC = -I./libgfx
LINK_GFX = -L./libgfx -lgfx
GFX_NAME = libgfx

IDIR = ./
ODIR = ./bin/

all: obj mlx libgfx libft $(NAME)

obj:
	@mkdir -p $(ODIR)

$(ODIR)%.o: %.c
	@$(CC) $(FLAGS) $(MLXINC) $(LIBGFXINC) $(LIBFTINC) -I $(IDIR) -c $< -o $@

libft: $(LIBFT)

libgfx: $(LIBGFX)

mlx: $(MLX)

$(LIBFT):
	@echo "\n-> Making $(FT_NAME) ...\n"
	@make -C ./libft re

$(LIBGFX):
	@echo "\n-> Making $(GFX_NAME) ...\n"
	@make -C ./libgfx re

$(MLX):
	@echo "\n-> Making $(MLX_NAME) ...\n"
	@make -C ./libgfx/minilibx re

$(NAME): $(OBJ)
	@echo "-> Compiling $(NAME)..."
	@$(CC) -o $(NAME) $(OBJ) $(LINK_MLX) $(LINK_GFX) $(LINK_FT)
	@echo "	* * * Done * * *"

clean:
	@echo "-> Cleaning $(NAME) object files..."
	@rm -rf $(OBJ)
	@make -C ./libft clean
	@make -C ./libgfx clean
	@make -C ./libgfx/minilibx clean

fclean: clean
	@echo "-> Cleaning $(NAME)...\n "
	@rm -rf $(NAME)
	@make -C ./libft fclean
	@make -C ./libgfx fclean

re: fclean all

norm:
	$(NORM)

love: all #credit to notoriousgtw

.PHONY: all clean fclean re


