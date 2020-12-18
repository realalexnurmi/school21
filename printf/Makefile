# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enena <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 17:51:07 by enena             #+#    #+#              #
#    Updated: 2020/12/18 22:50:17 by enena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

.PHONY: all clean fclean re bonus 

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIB = libft.a

LIB_PATH = libft

LIB_NAME = ft

HEADER_MAND = libftprintf.h

HEADER_BONUS = libftprintf_bonus.h

PRINTF_SRC = ft_printf.c

ENGINE_PATH = engine_srcs

ENGINE_SRCS =	find_handler.c\
				find_width_prec.c\
				ft_error_escape.c\
				funcdo_width_prec.c\
				general_func.c\
				list_free_utils.c\
				list_work_utils.c\
				tab_utils.c

MAND_PATH = srcs

MAND_SRCS = apply_handlers.c\
			check_mod_special_case.c\
			ft_lstprf_new.c\
			funcdo_convert_utils.c\
			handle_cs_prc_func.c\
			handle_diuxp_func.c\
			malloc_claim_content.c

BONUS ?= off

BONUS_PATH = srcs_bonus

BONUS_SRCS = claim_size_content_funcs_bonus.c\
			 malloc_size_content_funcs_bonus.c\
			 handle_nofge_func_bonus.c

ifeq ($(BONUS),on)
	DEFINE = BONUS
	BODY_SRCS = $(MAND_SRCS:%.c=%_bonus.c) $(BONUS_SRCS)
	HEADER_ALL = $(HEADER_BONUS)
else
	DEFINE = MANDATORY
	BODY_SRCS = $(MAND_SRCS)
	HEADER_ALL = $(HEADER_MAND)
endif

vpath %.c $(ENGINE_PATH) $(MAND_PATH) $(BONUS_PATH)
vpath %.h hdrs
vpath %.a $(LIB_PATH)
SRCS_ALL = $(PRINTF_SRC) $(ENGINE_SRCS) $(BODY_SRCS)

OBJ_ALL = $(SRCS_ALL:%.c=%.o)

REMOVE_O_ALL = $(OBJ_ALL) $(MAND_SRCS:%.c=%_bonus.o) $(BONUS_SRCS:%.c=%.o)

all: $(NAME)

$(LIB):
	$(MAKE) -C $(LIB_PATH)
	cp $(LIB_PATH)/$(LIB) $(NAME)

%.o: %.c $(HEADER_ALL)
	$(CC) -c $(FLAGS) -Ihdrs -D$(DEFINE) $< -o $@

$(NAME): $(LIB) $(OBJ_ALL)	
	ar rc $@ $(OBJ_ALL)
	ranlib $@

bonus:
	$(MAKE) BONUS:=on all

clean:
	$(MAKE) -C $(LIB_PATH) clean
	rm -f $(REMOVE_O_ALL)

fclean: clean
	$(MAKE) -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all
