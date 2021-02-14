# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enena <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 17:51:07 by enena             #+#    #+#              #
#    Updated: 2021/02/14 06:17:55 by enena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
#			draw_line\#

.PHONY: all clean fclean re norme recl

CC = gcc
NAME := cub3D
MAIN_FILE := test/a
SRCS_PATH := srcs
HDRS_PATH := hdrs
FOLDERS := general instruments error_handling naming_utils color_utils bmp_utils
SRCS_NAME := general_part_1\
			common_things_part_1\
			error_handling\
			naming_utils\
			color_utils_part_1\
			color_utils_part_2\
			color_utils_part_3\
			color_utils_part_4\
			color_utils_part_5\
			bmp_utils
BONUS_FOLDERS := bonus_folder
BONUS_SRCS_NAME := file
BONUS ?= off
ifeq ($(BONUS),on)
 SRCS_PATH = $(addsuffix _bonus,$(SRCS_PATH))
 HDRS_PATH = $(addsuffix _bonus,$(HDRS_PATH))
 FOLDERS += $(BONUS_FOLDERS)
 SRCS_NAME += $(BONUS_SRCS_NAME)
 SRCS_NAME = $(addsuffix _bonus,$(SRCS_NAME))
endif

LIB_LINK =$(addprefix -l,$(LIB)) $(addprefix -Llib,$(LIB))
LIBS_NAME := mlx ft 
LIBS := $(foreach LIB, $(LIBS_NAME), $(LIB_LINK)) -lz
FRM := -framework OpenGL -framework AppKit
#FLAGS := -Wall -Wextra -Werror
O_FILE = $(addsuffix .o, $(SRCS_NAME))
O_MAIN = $(addsuffix .o, $(MAIN_FILE))
RM_O_FILE := $(addsuffix .o, $(SRCS_NAME) $(BONUS_SRC_NAME))
C_PATH = $(addprefix $(SRCS_PATH)/, $(FOLDERS))

vpath %.c $(C_PATH)

all: $(NAME)

$(NAME): $(O_FILE) $(O_MAIN)
	@echo Build all .o with $(O_MAIN) in $@
	@$(CC) $^ $(FLAGS) -I$(HDRS_PATH) $(LIBS) $(FRM) -o $@

%.o: %.c
	@echo Compiling $< in $@
	@$(CC) -c $< $(FLAGS) -I$(HDRS_PATH) -o $@

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
