#include "../hdrs/mlx.h"
#include <stdio.h>
#include <unistd.h>
# define KEY_W			13
# define KEY_E			14
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

int n = 0;

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len_line;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct	s_xy
{
	int 	x;
	int 	y;
	void	*mlx;
	void	*win;
	t_image	img;
}				t_xy;

int		press(int key, t_xy *xy)
{
	if (key == KEY_W)
		xy->y--;
	if (key == KEY_A)
		xy->x--;
	if (key == KEY_S)
		xy->y++;
	if (key == KEY_D)
		xy->x++;
	//mlx_clear_window(xy->mlx, xy->win);
	mlx_put_image_to_window(xy->mlx, xy->win, xy->img.img, xy->x, xy->y);
	return (1);
}

int     main(void)
{
	t_xy	xy;
	t_image	img;

	xy.mlx = mlx_init();
	xy.win = mlx_new_window(xy.mlx, 2000, 1000, "TEST");
	xy.x = 50;
	xy.y = 50;
	img.img = mlx_new_image(xy.mlx, 2000, 1000, 0x0000FF00);
	xy.img.img = mlx_new_image(xy.mlx, 1000, 800, 0x00FF0000);
	mlx_put_image_to_window(xy.mlx, xy.win, img.img, 10, 10);
	mlx_put_image_to_window(xy.mlx, xy.win, xy.img.img, xy.x, xy.y);
	mlx_hook(xy.win, 2, 0, &press, &xy);
	mlx_loop(xy.mlx);
	return (0);
}