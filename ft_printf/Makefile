# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enena <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 17:51:07 by enena             #+#    #+#              #
#    Updated: 2021/01/21 01:43:09 by enena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

.PHONY: all clean fclean re bonus norme recl

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf.a

LIB = libft.a

LIB_PATH = libft

PREREC_LIB = $(shell $(MAKE) -s -C $(LIB_PATH) sayprec)

LIB_NAME = ft

HEADER_PRINTF = libftprintf.h

HEADERS_NAME = srcs

ENGINE_NAME =	ft_printf\
				find_handler\
				find_width_prec\
				ft_error_escape\
				funcdo_width_prec\
				general_func\
				list_free_utils\
				list_work_utils\
				tab_utils\
				littlethings

JOINT_NAME = apply_handlers\
			 check_mod_special_case\
			 ft_lstprf_new\
			 funcdo_convert_utils\
			 handle_cs_prc_func\
			 handle_diuxp_func\
			 malloc_claim_content

BONUS ?= on

BONUS_NAME = claim_size_content_funcs\
			 malloc_size_content_funcs\
			 handle_nofge_func\
			 extention_handlers\
			 g_converter

ifeq ($(BONUS),on)
	DEFINE = BONUS
	INTER_ENGINE_SUF = _bp
	INTER_SUF = _bonus
	OPOSITE_ENGINE_SUF = _mp
	OPOSITE_SUF = _mandatory
	BODY_NAME = $(JOINT_NAME) $(BONUS_NAME)
	OPOSITE_NAME = $(JOINT_NAME)
else
	DEFINE = MANDATORY
	INTER_ENGINE_SUF = _mp
	INTER_SUF = _mandatory
	OPOSITE_ENGINE_SUF = _bp
	OPOSITE_SUF = _bonus
	BODY_NAME = $(JOINT_NAME)
	OPOSITE_NAME = $(JOINT_NAME) $(BONUS_NAME)
endif

ENGINE_PATH = engine

SRCS_PATH = $(addsuffix $(INTER_SUF), srcs)

O_ENGINE = $(addsuffix .o, $(addsuffix $(INTER_ENGINE_SUF), $(ENGINE_NAME)))

O_BODY = $(addsuffix .o, $(addsuffix $(INTER_SUF), $(BODY_NAME)))

O_ALL = $(O_ENGINE) $(O_BODY)

O_ENGINE_GOAL = $(O_ENGINE:%$(INTER_ENGINE_SUF).o=%.o) 

O_BODY_GOAL = $(O_BODY:%$(INTER_SUF).o=%.o)

O_ALL_GOAL = $(O_ENGINE_GOAL) $(O_BODY_GOAL)

O_OPOSITE_ENGINE = $(addsuffix .o, $(addsuffix $(OPOSITE_ENGINE_SUF), $(ENGINE_NAME)))

O_OPOSITE_BODY = $(addsuffix .o, $(addsuffix $(OPOSITE_SUF), $(OPOSITE_NAME)))

O_OPOSITE = $(O_OPOSITE_ENGINE) $(O_OPOSITE_BODY)

O_REMOVE = $(addsuffix .o, $(ENGINE_NAME) $(JOINT_NAME) $(BONUS_NAME)) $(O_ALL) $(O_OPOSITE)

HEADER_SRCS = $(addsuffix .h, $(addsuffix $(INTER_SUF), $(HEADER_NAME)))

ARGS = rcs

vpath %.a $(LIB_PATH)

vpath %.h hdrs

vpath %.c $(ENGINE_PATH) $(SRCS_PATH)

all: $(NAME)

$(NAME): $(LIB) $(O_ALL)
	ranlib $@

$(LIB): 
	@$(MAKE) -C $(LIB_PATH)
	cp $(LIB_PATH)/$(LIB) $(NAME)

%$(INTER_ENGINE_SUF).o: %.c $(HEADER_PRINTF)
	$(CC) $(FLAGS) -I. -D$(DEFINE) $< -o $@
	cp $@ $(@:%$(INTER_ENGINE_SUF).o=%.o)
	ar rc $(NAME) $(@:%$(INTER_ENGINE_SUF).o=%.o)

%$(INTER_SUF).o: %$(INTER_SUF).c $(HEADER_SRCS)
	$(CC) $(FLAGS) -I. -D$(DEFINE) $< -o $@
	cp $@ $(@:%$(INTER_SUF).o=%.o)
	ar rc $(NAME) $(@:%$(INTER_SUF).o=%.o)

bonus:
	@$(MAKE) BONUS:=on all

clean:
	@$(MAKE) -C $(LIB_PATH) clean
	@rm -rf $(O_REMOVE)

fclean: clean
	@$(MAKE) -C $(LIB_PATH) fclean
	@rm -f $(NAME)

re: fclean all

norme:
	@$(MAKE) -C $(LIB_PATH) norme
	@norminette engine/*.c
	@norminette srcs_mandatory/*.c
	@norminette srcs_bonus/*.c
	@norminette hdrs/*.h
	@norminette ft_printf.c
	@norminette libftprintf.h

recl:
	@make re && make clean

%:
	@echo "Can't find rule for target $@"
