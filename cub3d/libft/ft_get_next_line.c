/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 05:39:07 by enena             #+#    #+#             */
/*   Updated: 2021/02/04 05:51:02 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (!(*line = ft_strdup(*buf)))
		return (-1);
	tmp = ft_sec_free(tmp);
	tmp = *buf;
	if (!(*buf = ft_strdup(find_n + 1)))
		return (-1);
	tmp = ft_sec_free(tmp);
	find_n = NULL;
	return (1);
}

static int	take_buff(int fd, char **line, char **buf)
{
	int				ret;
	char			*tmp;
	char			*mem;

	if (!(mem = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	ret = BUFFER_SIZE + 1;
	while (ret)
		mem[--ret] = '\0';
	while ((ret == 0) && ((ret = read(fd, mem, BUFFER_SIZE)) > 0))
	{
		mem[ret] = '\0';
		if (*buf)
		{
			tmp = *buf;
			if (!(*buf = ft_strjoin(tmp, mem)))
				return (-1);
			tmp = ft_sec_free(tmp);
		}
		else if (!(*buf = ft_strdup(mem)))
			return (-1);
		ret = n_check_line(buf, line);
	}
	mem = ft_sec_free(mem);
	return (ret);
}

int			ft_get_next_line(int fd, char **line)
{
	static t_buf	buf[OPEN_MAX];

	if ((fd < 0) || (fd >= OPEN_MAX) || (read(fd, buf[fd].buf, 0) < 0)
			|| !(line) || (BUFFER_SIZE <= 0))
		return (-1);
	if (!(*line = ft_strdup("\0")))
		return (-1);
	if (buf[fd].buf)
		if (!!((buf[fd].ret = n_check_line(&buf[fd].buf, line))))
			return (buf[fd].ret);
	buf[fd].ret = take_buff(fd, line, &buf[fd].buf);
	if (!buf[fd].ret && buf[fd].buf)
	{
		*line = ft_sec_free(*line);
		if (!(*line = ft_strdup(buf[fd].buf)))
			return (-1);
		buf[fd].buf = ft_sec_free(buf[fd].buf);
	}
	return (buf[fd].ret);
}
