#
#

NAME = libmlx.a
SRC = mlx_rgb.c mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)
CFLAGS += -O2

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n-> Creating archive $(NAME)...\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "-> Cleaning $(NAME) object files...\n"
	@rm -f $(NAME) $(OBJ) *~
	@rm -f mlx_app

re: clean all
