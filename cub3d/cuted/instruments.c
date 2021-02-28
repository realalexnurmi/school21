/*
** Adding data color into pxl image color with intensity {0.0 ~ < 1.0}
*/
void	add_pxl_to_img(t_image *data, t_pxl pxl, float intensity)
{
	char	*dst;
	int		offset;
	t_clr	base;
	t_clr	add;

	if (intensity >= 1.0)
		put_pxl_to_img(data, pxl);
	else
	{
		if (intensity < 0.1875)
			intensity = 0.1875;
		offset = (pxl.y * data->len_line + pxl.x * (data->bpp / 8));
		dst = data->addr + offset;
		base = get_clr(*(t_uint*)dst);
		set_clr_br(&base, 1.0 - intensity);
		add = took_clr(pxl.rule);
		set_clr_br(&add, intensity);
		*(t_uint*)dst = get_color_data(get_merge_clr(base, add));
	}
}

/*
** Convert coordinate into point
*/
t_point	get_point(float x, float y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

/*
** Convert point into pixel
*/
t_pxl	get_pxl(t_point *crd, t_)
{
	t_pxl	pxl;

	pxl.x = trunc(crd.x);
	pxl.y = trunc(crd.y);
	pxl.clr = clr;
	return (pxl);
}