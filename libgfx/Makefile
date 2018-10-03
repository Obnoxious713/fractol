# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 15:55:00 by jfleisch          #+#    #+#              #
#    Updated: 2018/07/21 15:55:01 by jfleisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.a
NAME2 = libgfx

FLAGS = -Wall -Wextra -Werror -g

CC = gcc

ODIR = ./bin/
IDIR = ./

SRC = initializers.c

OBJ = $(SRC:.c=.o)

O = $(addprefix $(ODIR), $(OBJ))

EXT = $(IDIR)$(NAME:.a=.h)

MLXINC = -I./minilibx
LFTINC = -I../libft

all: $(NAME)

love: all

norm:
	norminette $(S)

$(NAME): $(O) $(EXT)
	@echo "-> Creating archive $(NAME)...\n"
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(ODIR)%.o: %.c
	@$(CC) $(FLAGS) $(MLXINC) $(LFTINC) -c $< -o $@

$(O): | ./bin

./bin:
	@mkdir $(ODIR)

clean:
	@echo "-> Cleaning $(NAME2) object files..."
	@rm -rf $(O)

fclean: clean
	@echo "-> Cleaning $(NAME)...\n"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
