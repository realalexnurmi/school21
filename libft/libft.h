/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:33:47 by enena             #+#    #+#             */
/*   Updated: 2020/12/15 04:04:08 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Standart library
** Uses:	functions: malloc, free
*/
# include <stdlib.h>

/*
** Standart definition
** Uses:	macro: NULL, type: size_t  - also in <stdlib>
** 			types: wchar_t, ptrdiff_t
*/
# include <stddef.h>

# include <wchar.h>

/*
** Library of limits
** Uses:	all definition macros {TYPE}_MAX and {TYPE}_MIN
*/
# include <limits.h>

/*
** Library for operating in POSIX
** Uses:	classic (i would say pleasantly) function:
**			write, read, close
*/
# include <unistd.h>

/*
** My type and macros boolean for Norme like <stdbool>
*/
typedef int						t_bool;
# define TRUE 1
# define FALSE 0

/*
** Redefinition UNSIGNED type for shorter cast
*/
typedef	signed char				t_schar;
typedef unsigned char			t_uchar;
typedef unsigned int			t_uint;
typedef unsigned long int		t_ulint;
typedef unsigned long long int	t_ullint;
/*
** Basic style for list structure: Singly linked list ~ SLL
*/
typedef struct	s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;

/*
** Family of list-based functions
*/
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
														void (*del)(void *));
/*
** Function's to convert string to number like real atoi, atol, atoll <stdlib>
*/
int				ft_atoi(const char *str);
long int		ft_atol(const char *str);
long long int	ft_atoll(const char *str);
/*
**
*/
char			*ft_itoa(int n);
char			*ft_lltoa_base(long long int n, t_uchar base);
char			*ft_ulltoa(t_ullint n);
/*
** Function's for analize character.
** My functions are similar to macros ctype.h returning TRUE (1) and FALSE(0)
** The accepted value [c] must be represented by an unsigned char.
*/
t_bool			ft_isupper(int c);
t_bool			ft_islower(int c);
t_bool			ft_isdigit(int c);
t_bool			ft_isalpha(int c);
t_bool			ft_isalnum(int c);
t_bool			ft_isascii(int c);
t_bool			ft_isprint(int c);
t_bool			ft_isspace(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
/*
** Comment
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *haystack, const char *needle,
																	size_t len);
char			*ft_strrchr(const char *s, int c);
/*
** Functions to convert wide character/string in MB (UTF-8)
*/
char			*ft_took_next_char(char *mbs);
size_t			ft_get_charcount(size_t cnt_byte, char *mbs);
size_t			ft_mblen(char *mbc);
size_t			ft_wclen(wchar_t wc);
size_t			ft_wstrlen_byte(wchar_t *wstring);
wchar_t			ft_mbtowc(char *mbc);
char			*ft_wctomb(wchar_t src, char *dest);
char			*ft_wcstombs(wchar_t *wstring);
/*
** Own function to write output
*/
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char *c, int fd);
void			ft_putstr_fd(char *s, int fd);

#endif
