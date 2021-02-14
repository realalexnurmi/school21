	//set_br_clr(&clr, 0.1);
	// TEST SQUARE
	// int x = 0;
	// int y = 0;
	// while (x < 100)
	// {
	// 	while (y < 100)
	// 	{
	// 		pxl_to_img(&data, get_pxl(get_point(x, y), clr));
	// 		y++;
	// 	}
	// 	y = 10;
	// 	x++;
	// }
	//TEST LINE IN LITTLE STAR
	// t_line line;
	// line.p1 = get_point(100, 100);
	// line.p2 = get_point(60, 100);
	// draw_line(&data, line);
	// line.p2 = get_point(60, 80);
	// draw_line(&data, line);
	// line.p2 = get_point(60, 60);
	// draw_line(&data, line);
	// line.p2 = get_point(80, 60);
	// draw_line(&data, line);
	// line.p2 = get_point(100, 60);
	// draw_line(&data, line);
	// line.p2 = get_point(120, 60);
	// draw_line(&data, line);
	// line.p2 = get_point(140, 60);
	// draw_line(&data, line);
	// line.p2 = get_point(140, 80);
	// draw_line(&data, line);
	// line.p2 = get_point(140, 100);
	// draw_line(&data, line);
	// line.p2 = get_point(140, 120);
	// draw_line(&data, line);
	// line.p2 = get_point(140, 140);
	// draw_line(&data, line);
	// line.p2 = get_point(120, 140);
	// draw_line(&data, line);
	// line.p2 = get_point(100, 140);
	// draw_line(&data, line);
	// line.p2 = get_point(80, 140);
	// draw_line(&data, line);
	// line.p2 = get_point(60, 140);
	// draw_line(&data, line);
	// line.p2 = get_point(60, 120);
	// draw_line(&data, line);
	//TEST SOME PARALLEL LINE
	// t_line line;
	// int i = 0;
	// while (i < 100)
	// {
	// line.p1 = get_point(60 + i, 10);
	// line.p2 = get_point(40 + i, 150);
	// draw_line(&data, line);
	// i++;
	// IN MAIN A
	// int			fd = open("file", O_RDONLY);
	// char		*line;
	// t_bool		lastline;
	// int			retgnl;
	// lastline = FALSE;
	// ft_set_output_attr(1, FG_RED);
	// ft_set_output_attr(1, UNDERLINE);
	// printf("%d\n", fd);
	// while (((retgnl = ft_get_next_line(fd, &line)) > 0) || 
	// 			(lastline = (!(lastline) && (retgnl == 0))))
	// {
	// 	write(1, line, ft_strlen(line));
	// 	write(1, "\n", 1);
	// 	line = ft_sec_free(line);
	// }
	// if (retgnl)
	// 	printf("ERROR\n");
	// close(fd);
	//sleep(30);
	// return(0);
	// }