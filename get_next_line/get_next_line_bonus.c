/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:09:01 by enena             #+#    #+#             */
/*   Updated: 2021/02/04 05:51:06 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*ft_strdup(const char *s)
{
	char	*p_copy;
	size_t	len;

	len = ft_strlen(s);
	if (!(p_copy = malloc((len + 1) * sizeof(char))) || !s)
		return (NULL);
	p_copy[len] = '\0';
	while (len--)
		p_copy[len] = s[len];
	return (p_copy);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*js;

	if ((!s1) && (!s2))
		return (NULL);
	s1len = (s1 ? ft_strlen(s1) : 0);
	s2len = (s2 ? ft_strlen(s2) : 0);
	if (!(js = malloc((s1len + s2len + 1) * sizeof(char))))
		return (NULL);
	js[s1len + s2len] = '\0';
	ft_strlcpy(js, (s1 ? s1 : s2), (s1 ? s1len + 1 : s2len + 1));
	if (s2)
		ft_strlcat(js, s2, s1len + s2len + 1);
	return (js);
}

int				take_buff(int fd, char **line, char **buf)
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

int				n_check_line(char **buf, char **line)
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

int				get_next_line(int fd, char **line)
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
