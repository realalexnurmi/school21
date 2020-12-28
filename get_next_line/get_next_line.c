/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:09:01 by enena             #+#    #+#             */
/*   Updated: 2020/12/28 22:24:38 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strdup(const char *s)
{
	char	*p_copy;
	size_t	len;

	len = ft_strlen(s);
	if (!(p_copy = malloc((len + 1) * sizeof(char))) || !s)
		return (NULL);
	ft_memset(p_copy, '\0', (len + 1) * sizeof(char));
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
	ft_memset(js, '\0', (s1len + s2len + 1) * sizeof(char));
	ft_strlcpy(js, (s1 ? s1 : s2), (s1 ? s1len + 1 : s2len + 1));
	if (s2)
		ft_strlcat(js, s2, s1len + s2len + 1);
	return (js);
}

int				take_buff(int fd, char **line, char *mem, char **buf)
{
	int				ret;
	char			*tmp;

	while (((ret = read(fd, mem, BUFFER_SIZE)) > 0))
	{
		mem[ret] = '\0';
		if (*buf)
		{
			tmp = *buf;
			*buf = ft_strjoin(tmp, mem);
			free(tmp);
		}
		else
			*buf = ft_strdup(mem);
		if (n_check_line(buf, line))
			break ;
	}
	ret = (ret < BUFFER_SIZE && ret > 0) ? 0 : ret;
	return (ret > 0 ? 1 : ret);
}

unsigned char	n_check_line(char **buf, char **line)
{
	char	*find_n;
	char	*tmp;

	find_n = *buf;
	while (*find_n != '\n')
		if (!(*find_n++))
			return (0);
	*find_n = '\0';
	*line = ft_strdup(*buf);
	tmp = *buf;
	*buf = ft_strdup(find_n + 1);
	free(tmp);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*buf[OPEN_MAX];
	char			*mem;
	int				ret;

	if ((read(fd, buf[fd], 0) < 0) || !(line) || (BUFFER_SIZE <= 0)
			|| !(mem = malloc(BUFFER_SIZE * sizeof(char) + 1)))
		return (-1);
	if (buf[fd] && n_check_line(&buf[fd], line))
		return (1);
	ft_memset(mem, '\0', BUFFER_SIZE);
	ret = take_buff(fd, line, mem, &buf[fd]);
	if (mem)
		free(mem);
	if (!ret)
	{
		*line = ft_strdup("\0");
		buf[fd] = NULL;
	}
	return (ret);
}
