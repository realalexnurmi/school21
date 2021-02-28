#
#

NAME =	libmlx.a
SRC =	mlx_shaders.c\
		mlx_png.c\
		mlx_int_str_to_wordtab.c\
		mlx_new_window.m\
		mlx_get_screen_size.m\
		mlx_init_loop.m\
		mlx_new_image.m\
		mlx_mouse.m
OBJ1 = $(SRC:%.c=%.o)
OBJ = $(OBJ1:%.m=%.o)
CFLAGS += -O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $?
	ranlib $@

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
