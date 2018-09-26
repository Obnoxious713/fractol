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
		draw.c \
		gfx.c \
		hooks.c \
		image.c \
		mouse_hooks.c \
		toggle_keys.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = ./libft/libft.a
LIBFTINC = -I./libft
LINK_FT = -L./libft -lft

MLX = ./libgfx/minilibx/libmlx.a
MLXINC = -I./libgfx/minilibx
LINK_MLX = -L./libgfx/minilibx -lmlx -framework OpenGL -framework AppKit

LIBGFX = ./libgfx/libgfx.a
LIBGFXINC = -I./libgfx
LINK_GFX = -L./libgfx -lgfx

SRCDIR = ./
INCDIR = ./
OBJDIR = ./bin/

all: obj mlx libgfx libft $(NAME)

gfx:
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@make -C ./libgfx fclean
	@make

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) $(MLXINC) $(LIBGFXINC) $(LIBFTINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

libgfx: $(LIBGFX)

mlx: $(MLX)

$(LIBFT):
	@echo "\n-> Making libft ...\n"
	@make -C ./libft re

$(LIBGFX):
	@echo "\n-> Making libgfx ...\n"
	@make -C ./libgfx re

$(MLX):
	@echo "\n-> Making minilibx ...\n"
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


