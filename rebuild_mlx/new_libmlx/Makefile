#
#

NAME = libmlx.a
SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c mlx_get_screen_size.m
SRC += mlx_png.c mlx_mouse.m
OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)
CFLAGS += -O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $?
	ranlib $@

clean:
	rm -f $(OBJ)
#rm -f mlx_app

fclean: clean
	rm -f $(NAME)

re: fclean all
