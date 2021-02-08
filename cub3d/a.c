#include "hdrs/libft.h"
#include <fcntl.h>
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#define CNT 3

typedef enum	e_index
{
	A,
	B,
	C
}				t_index;

int main()
{
	// int			fd = open("file", O_RDONLY);
	// char		*line;
	// t_bool		lastline;
	// int			retgnl;
	int		*arr;
	int		i;

	arr = malloc(CNT * sizeof(int));
	arr[A] = 3;
	arr[B] = 2;
	arr[C] = 1;
	i = 0;
	while (i < CNT)
	{
		printf("%d\n", arr[i]);
		i++;
	}
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
	// //sleep(30);
	// return(0);
}