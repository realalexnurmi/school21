/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:17:43 by enena             #+#    #+#             */
/*   Updated: 2020/11/13 22:40:21 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_countwrd(char const *s, char c)
{
	unsigned int	wrdcnt;

	wrdcnt = 0;
	while (*s)
	{
		if (*s != c)
			wrdcnt++;
		while (*s && (*s != c))
			s++;
		while (*s && (*s == c))
			s++;
	}
	return (wrdcnt);
}

static char const	*ft_begin_end_wrd(char const *s, char c, char on)
{
	if (on == 'b')
		while (*s == c && *s)
			s++;
	if (on == 'e')
		while (*s != c && *s)
			s++;
	return (s);
}

static size_t		ft_wrdlen(char const *s, char c)
{
	size_t			wrdlen;

	wrdlen = 0;
	while (*s != c && *s)
	{
		s++;
		wrdlen++;
	}
	return (wrdlen);
}

char				**ft_split(char const *s, char c)
{
	unsigned int	wrdcnt;
	unsigned int	curwrd;
	char			**wrdtb;

	if (!s)
		return (NULL);
	wrdcnt = ft_countwrd(s, c);
	if (!(wrdtb = malloc(sizeof(char *) * (wrdcnt + 1))))
		return (NULL);
	wrdtb[wrdcnt] = NULL;
	if (wrdcnt)
	{
		curwrd = 0;
		while (curwrd < wrdcnt)
		{
			s = ft_begin_end_wrd(s, c, 'b');
			wrdtb[curwrd] = ft_substr(s, 0, ft_wrdlen(s, c));
			if (!wrdtb[curwrd])
				return (wrdtb = ft_free_tab(wrdtb));
			curwrd++;
			s = ft_begin_end_wrd(s, c, 'e');
		}
	}
	return (wrdtb);
}
