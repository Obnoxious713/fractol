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

NAME = libftcomplex.a
NAME2 = complex

FLAGS = -Wall -Wextra -Werror -g

CC = gcc

ODIR = ./bin/
IDIR = ./

SRC = ft_create_complex.c \
		ft_create_complex_polar.c \
		ft_recreate_complex.c \
		ft_recreate_complex_polar.c \
		ft_cadd.c \
		ft_csub.c \
		ft_cmult.c \
		ft_cdiv.c \
		ft_cpow.c

OBJ = $(SRC:.c=.o)

O = $(addprefix $(ODIR), $(OBJ))

EXT = $(IDIR)$(NAME:.a=.h)

all: $(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader

$(NAME): $(O) $(EXT)
	@echo "-> Creating archive $(NAME)...\n"
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(ODIR)%.o: %.c
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@

$(O): | ./bin

./bin:
	@mkdir -p $(ODIR)

clean:
	@echo "-> Cleaning $(NAME2) object files..."
	@rm -rf $(O)

fclean: clean
	@echo "-> Cleaning $(NAME)...\n"
	@rm -rf $(NAME)

re: fclean all
