/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 23:37:08 by enena             #+#    #+#             */
/*   Updated: 2021/03/01 23:43:11 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	read_part(void *part, const int fd,
									char **line, const t_analyzer analyzer)
{
	int			retgnl;
	t_bool		lastline_drop;
	int			a;

	lastline_drop = false;
	a = 0;
	if (a == 0)
	{
		while (((retgnl = ft_get_next_line(fd, line)) > 0) ||
			(lastline_drop = (!(lastline_drop) && (retgnl == 0))))
		{
			if (!(analyzer(part, *line, &lastline_drop)))
			{
				if (!(lastline_drop))
					*line = ft_sec_free(*line);
				return (lastline_drop);
			}
			*line = ft_sec_free(*line);
		}
	}
	*line = ft_sec_free(*line);
	if (retgnl)
		return (error_handler(err_read_fail));
	return (true);
}
