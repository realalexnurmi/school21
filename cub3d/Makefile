# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enena <enena@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 17:51:07 by enena             #+#    #+#              #
#    Updated: 2021/02/28 11:31:17 by enena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

.PHONY: all clean fclean re norme recl

CC:= gcc
NAME:= cub3D
HDRS_PATH:= hdrs
SRCS_PATH:= srcs

FOLDERS:=	main
SRCS_NAME:=		cub3d

FOLDERS+=	initialization
SRCS_NAME+=		game_master_init\
				settings_linker_init\
				setters_settings\
				read_part_with_analyzer\
				map_init\
				map_convert_utils\
				images

#FOLDERS+=	general
#SRCS_NAME +=	general_part_1

#FOLDERS+=	instruments
#SRCS_NAME+=		common_things_part_1\
				draw_line

FOLDERS+=	error_handling
SRCS_NAME+=		error_handling\
				free_utils

#FOLDERS+=	naming_utils
#SRCS_NAME+=		naming_utils

#FOLDERS+=	color_utils
#SRCS_NAME+=		color_utils_part_1\
				color_utils_part_2\
				color_utils_part_3\
				color_utils_part_4\
				color_utils_part_5

#FOLDERS+=	bmp_utils
#SRCS_NAME+=		bmp_utils

BONUS_FOLDERS+=	bonus_folder
BONUS_SRCS_NAME+=	file

BONUS ?= off
ifeq ($(BONUS),on)
 SRCS_PATH=		$(addsuffix _bonus,$(SRCS_PATH))
 HDRS_PATH=		$(addsuffix _bonus,$(HDRS_PATH))
 FOLDERS+=		$(BONUS_FOLDERS)
 SRCS_NAME+=	$(BONUS_SRCS_NAME)
 SRCS_NAME=		$(addsuffix _bonus,$(SRCS_NAME))
endif

LIB_LINK=	$(addprefix -l,$(LIB)) $(addprefix -Llib,$(LIB))
LIBS_NAME:=	mlx ft
LIBS:=		$(foreach LIB,$(LIBS_NAME),$(LIB_LINK)) -lz
FRM:=		-framework OpenGL -framework AppKit
FLAGS := -g -Wall -Wextra -Werror
O_FILE=		$(addsuffix .o,$(SRCS_NAME))
O_MAIN=		$(addsuffix .o,$(MAIN_FILE))
RM_O_FILE:=	$(addsuffix .o,$(SRCS_NAME) $(BONUS_SRC_NAME))
C_PATH=		$(addprefix $(SRCS_PATH)/,$(FOLDERS))

vpath %.c $(C_PATH)

all: $(NAME)

$(NAME): $(O_FILE)
	@echo Build all .o in $@
	make -C libft bonus
	make -C libmlx
	@$(CC) $^ $(FLAGS) -I$(HDRS_PATH) $(LIBS) $(FRM) -o $@

%.o: %.c
	@echo Compiling $< in $@
	$(CC) -c $< $(FLAGS) -I$(HDRS_PATH) -o $@

clean: 
	@echo Cleaning .o file...
	@rm -f $(RM_O_FILE)
	@echo Done!

fclean: clean
	@echo Remove $(NAME)
	@rm -f $(NAME)

re: fclean all

norme:
	@clear && clear
	@norminette ./*.c
	@norminette ./*.h

recl:
	@make re && make clean

%:
	@echo "Can't find rule for target $@"
