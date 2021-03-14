/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:33:47 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 05:13:22 by enena            ###   ########.fr       */
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

/*
** Library for wide char
** Uses:	types: wchar_t (also), wint_t
*/
# include <wchar.h>

/*
** System type
** Uses:	many standart types: size_t, ssize_t
*/
# include <sys/types.h>

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 65534
# endif

typedef struct	s_buf
{
	int		ret;
	char	*buf;
}				t_buf;
/*
** Redefinition UNSIGNED type for shorter cast
*/
typedef	signed char				t_schar;
typedef unsigned char			t_uchar;
typedef unsigned short int		t_usint;
typedef unsigned int			t_uint;
typedef unsigned long int		t_ulint;
typedef unsigned long long int	t_ullint;

/*
** My type and macros boolean for Norme like <stdbool> but unsigned char
*/
typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

/*
** Basic style for list structure: Singly linked list ~ SLL
*/
typedef struct	s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;

/*
** Struct for convert double
*/
typedef struct	s_binary_d
{
	char			sign;
	t_ullint		mant;
	long long int	exp;
}				t_binary_d;

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
** My toa
*/
char			*ft_itoa(int n);
char			*ft_lltoa_base(long long int n, t_uchar base);
char			*ft_ulltoa_base(t_ullint n, t_uchar base);
char			*ft_dtoa(double dnum, int prec);
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
t_bool			ft_isodd(int c);
t_bool			ft_iseven(int c);
t_bool			ft_isanum(char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_lower(char *s);
void			ft_upper(char *s);
/*
** Comment
*/
void			*ft_sec_free(void *p);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_zerroc(size_t count);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
char			**ft_split(char const *s, char c);
char			**ft_free_tab(char **removetb);
size_t			ft_tab_size(char **tab);
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
size_t			ft_charcount(const char *s, int c);
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
typedef enum	e_text_attr
{
	DEFAULT_ALL,
	BOLD,
	LOW_INTENSIVE,
	UNDERLINE,
	BLINK,
	REVERSE_BG_FG,
	DEFAULT_INTENSIVE,
	CNCL_UNDERLINE,
	CNCL_BLINK,
	CNCL_REVERSE_BG_FG,
	FG_BLACK,
	FG_RED,
	FG_GREEN,
	FG_YELLOW,
	FG_BLUE,
	FG_PURPLE,
	FG_CYAN,
	FG_GRAY,
	BG_BLACK,
	BG_RED,
	BG_GREEN,
	BG_YELLOW,
	BG_BLUE,
	BG_PURPLE,
	BG_CYAN,
	BG_GRAY
}				t_text_attr;

t_bool			ft_set_output_attr(int fd, t_text_attr attr);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char *c, int fd);
size_t			ft_putstr_fd(char *s, int fd);
/*
** Functions to strings arithmetic
*/
void			ft_sumnumstr(char *sum, char *add);
void			ft_mulnumstr(char *comp, char *mult);
char			*ft_pownumstr(char *base, char *pow);
char			*ft_halfnumstr(char *quo);
/*
** Utils for dtoa
*/
t_binary_d		ft_getmemdouble(double dnum);
char			*ft_doprec_fstr(char *num, int prec);
/*
** Swap utils
*/
void			ft_swap_p(void **a, void **b);
void			ft_swap_ch(char *a, char *b);
t_bool			ft_swap(void *v1, void *v2, size_t size);
/*
** Convert signed(all) to unsigned (size_t)
*/
size_t			ft_stous(long long int signd);
/*
** GNL
*/
int				ft_get_next_line(int fd, char **line);

typedef struct	s_bitmapfileheader
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}				t_bitmapfileheader;

typedef struct	s_bitmapinfo
{
	int		size;
	int		width;
	int		height;
	short	planes;
	short	bitcount;
	int		compression;
	int		sizeimage;
	int		xpelspermeter;
	int		ypelspermeter;
	int		clrused;
	int		clrimportant;
}				t_bitmapinfo;

/*
** Sructure for setting/storage bmpfile image
*/
typedef struct	s_bmpfile
{
	t_bitmapfileheader	fileheader;
	t_bitmapinfo		info;
	char				*data;
}				t_bmpfile;

/*
** My functions ((!!read!!))/write bmp file ((!!in!!))/from setted structure
** ((!!COMING SOON!!))
*/
t_bool			ft_write_bmp(int fd, t_bmpfile *bitmap);

/*
** Check extn
*/
t_bool			ft_check_extention(const char *name, const char *extn);

#endif
