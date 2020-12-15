# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enena <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 17:51:07 by enena             #+#    #+#              #
#    Updated: 2020/12/15 04:04:24 by enena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

.PHONY: all clean fclean re recl bonus

CC = gcc

NAME = libft.a

HEADER = libft.h 

SRC_NAME =  ft_atoi\
			ft_atol\
			ft_atoll\
			ft_bzero\
			ft_calloc\
			ft_isalnum\
			ft_isalpha\
			ft_isascii\
			ft_isupper\
			ft_islower\
			ft_isspace\
			ft_isdigit\
			ft_isprint\
			ft_itoa\
			ft_lltoa_base\
			ft_memccpy\
			ft_memchr\
			ft_memcmp\
			ft_memcpy\
			ft_memmove\
			ft_memset\
			ft_putendl_fd\
			ft_putnbr_fd\
			ft_putchar_fd\
			ft_putstr_fd\
			ft_split\
			ft_strchr\
			ft_strdup\
			ft_strjoin\
			ft_strlcat\
			ft_strlcpy\
			ft_strlen\
			ft_strncmp\
			ft_strmapi\
			ft_strnstr\
			ft_strrchr\
			ft_strtrim\
			ft_substr\
			ft_tolower\
			ft_toupper\
			ft_mblen\
			ft_took_next_char\
			ft_get_charcount\
			ft_mbtowc\
			ft_wctomb\
			ft_wcstombs\
			ft_wclen\
			ft_wstrlen_byte\

BONUS_NAME = ft_lstadd_back\
			 ft_lstadd_front\
			 ft_lstclear\
			 ft_lstdelone\
			 ft_lstiter\
			 ft_lstlast\
			 ft_lstmap\
			 ft_lstnew\
			 ft_lstsize\

FLAGS = -Wall -Wextra -Werror

O_FILE = $(addsuffix .o, $(SRC_NAME))

O_BONUS_FILE = $(addsuffix .o, $(BONUS_NAME)) 

O_ALL ?= $(O_FILE)

HEADER_ALL ?= $(HEADER)

all: $(NAME)

$(NAME): $(O_ALL)
	@ar rc $@ $?
	@ranlib $@

bonus:
	@make O_ALL:="$(O_FILE) $(O_BONUS_FILE)" all

%.o: %.c $(HEADER_ALL)
	$(CC) $(FLAGS) -c $< -o $@ 

clean: 
	@rm -f $(O_FILE) $(O_BONUS_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

recl:
	@make re && make clean
