/*
** Struct for line (Yep, i'm still normal, not crazy!)
*/
typedef struct	s_line
{
	t_point p1;
	t_point p2;
	void	*data;
}				t_line;

/*
** Color storage structure
*/
typedef struct				s_clr
{
	t_uchar a;
	t_uchar	r;
	t_uchar g;
	t_uchar b;
	float	br;
	float	tr;
}							t_clr;

/*
** Struct for coordinate
*/
typedef struct	s_point
{
	float	x;
	float	y;
}				t_point;

/*
** Struct for pixel
*/
typedef struct	s_pxl
{
	t_uint	x;
	t_uint	y;
	t_uint	clr;
}				t_pxl;