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

NAME = libftprintf.a
NAME2 = printf

FLAGS = -Wall -Wextra -Werror -g

CC = gcc

ODIR = ./bin/
IDIR = ./

SRC = ../ft_bzero.c \
		../ft_memalloc.c \
		../ft_putchar.c \
		../ft_putstr.c \
		../ft_putnbr.c \
		../ft_toupper.c \
		../ft_strlen.c \
		../ft_itoa.c \
		../ft_itoa_base.c \
		../ft_isdigit.c \
		../ft_strcpy.c \
		../ft_isalpha.c \
		../ft_atoi.c \
		../ft_strcmp.c \
		../ft_strtoupper.c \
		../ft_ltoa.c \
		../ft_ltoa_base.c \
		../ft_ultoa_base.c \
		../ft_wstrlen.c \
		../ft_printf.c \
		flags.c \
		ft_put_pf.c \
		helper.c \
		loc.c \
		parser.c \
		prec.c \
		print_flags.c \
		size.c \
		start.c \
		type_char.c \
		type_hex_int.c \
		type_hex_int_1.c \
		type_int.c \
		type_int_1.c \
		type.c

OBJ = $(SRC:.c=.o)

O = $(addprefix $(ODIR), $(OBJ))

EXT = $(IDIR)$(NAME:.a=.h)

all: $(NAME) extra

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

extra:
	@mv *.o $(ODIR)

clean:
	@echo "-> Cleaning $(NAME2) object files..."
	@rm -rf $(ODIR)*.o

fclean: clean
	@echo "-> Cleaning $(NAME)...\n"
	@rm -rf $(NAME)

re: fclean all
