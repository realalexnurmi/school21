/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:12:32 by enena             #+#    #+#             */
/*   Updated: 2020/12/30 08:49:44 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 65534
# endif

typedef struct		s_buf
{
	int		ret;
	char	*buf;
}					t_buf;

int					get_next_line(int fd, char **line);
int					n_check_line(char **mem, char **line);
int					take_buff(int fd, char **line, char **buf);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
void				*ft_sec_free(void *p);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
