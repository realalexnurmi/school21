#include "libft.h"
// Checking for '\n' in taken buffer
static int	n_check_line(char **buf, char **line)
{
	char	*find_n;
	char	*tmp;

	find_n = *buf;
	while (*find_n != '\n')
		if (!(*find_n++))
			return (0);
	*find_n = '\0';
	tmp = *line;
	*line = ft_strdup(*buf);
	if (!(*line))
		return (-1);
	tmp = ft_sec_free(tmp);
	tmp = *buf;
	*buf = ft_strdup(find_n + 1);
	if (!(*buf))
		return (-1);
	tmp = ft_sec_free(tmp);
	find_n = NULL;
	return (1);
}

static int	buff_fill(char **buf, char *mem)
{
	char			*tmp;

	if (*buf)
	{
		tmp = *buf;
		*buf = ft_strjoin(tmp, mem);
		if (!(*buf))
			return (-1);
		tmp = ft_sec_free(tmp);
	}
	else
	{
		*buf = ft_strdup(mem);
		if (!(*buf))
			return (-1);
	}
	return (0);
}

static int	take_buff(int fd, char **line, char **buf)
{
	int				ret;
	char			*mem;

	mem = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!(mem))
		return (-1);
	ret = read(fd, mem, BUFFER_SIZE));
	while (ret > 0)
	{
		mem[ret] = '\0';
		ret = buff_fill(buf, mem);
		if (ret)
			return (ret);
		ret = n_check_line(buf, line);
		if (ret)
			break ;
		ret = read(fd, mem, BUFFER_SIZE));
	}
	mem = ft_sec_free(mem);
	return (ret);
}

int	ft_get_next_line(int fd, char **line)
{
	static t_buf	buf[OPEN_MAX];

	if ((fd < 0) || (fd >= OPEN_MAX) || (read(fd, buf[fd].buf, 0) < 0)
		|| !(line) || (BUFFER_SIZE <= 0))
		return (-1);
	*line = ft_strdup("\0");
	if (!(*line))
		return (-1);
	if (buf[fd].buf)
	{
		buf[fd].ret = n_check_line(&buf[fd].buf, line);
		if (buf[fd].ret)
			return (buf[fd].ret);
	}		
	buf[fd].ret = take_buff(fd, line, &buf[fd].buf);
	if (!buf[fd].ret && buf[fd].buf)
	{
		*line = ft_sec_free(*line);
		*line = ft_strdup(buf[fd].buf);
		if (!(*line))
			return (-1);
		buf[fd].buf = ft_sec_free(buf[fd].buf);
	}
	return (buf[fd].ret);
}
