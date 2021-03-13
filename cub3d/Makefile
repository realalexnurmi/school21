# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enena <enena@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 17:51:07 by enena             #+#    #+#              #
#    Updated: 2021/03/14 02:37:07 by enena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

.PHONY: all clean fclean re norme recl

CC:= gcc
NAME:=		cub3D
HDRS_DIR:=	hdrs
SRCS_DIR:=	srcs
OBJS_DIR:=	objs

DIRS:=		main
SRCS_FILE:=		cub3d.c

DIRS+=		bmp_utils
SRCS_FILE+=		bmp_utils.c

DIRS+=		error_handling
SRCS_FILE+=		error_handling.c\
				free_utils.c

DIRS+=		general
SRCS_FILE +=	game.c\
				key_work.c\
				react_keys_part_1.c\
				react_keys_part_2.c\
				do_bmp.c\
				raycast.c

DIRS+=		initialization
SRCS_FILE+=		game_master_init.c\
				settings_linker_init.c\
				setters_settings.c\
				read_part_with_analyzer.c\
				map_init.c\
				map_convert_utils.c\
				images.c\
				keys_init.c\
				render_init.c

DIRS+=		instruments
SRCS_FILE+=		common_things_part_1.c\
				algebra_part_1.c\
				drawning.c\
				wall_calculate.c\
				sprite_calculate.c\
				quick_sort_sprite.c

DIRS+=		naming_utils
SRCS_FILE+=		naming_utils.c

LIBS_NAME:=	mlx ft
LIBS_DIRS:= $(addprefix lib,$(LIBS_NAME))
LIBS_FILE:= $(addsuffix .a,$(addprefix lib,$(LIBS_NAME)))
LIB_LINK=	$(addprefix -l,$(LIB)) $(addprefix -Llib,$(LIB))
LIBS_LINK:=	$(foreach LIB,$(LIBS_NAME),$(LIB_LINK)) -lz
FRM:=		-framework OpenGL -framework AppKit
FLAGS:=		-Wall -Wextra -Werror
OBJS_FILE=	$(SRCS_FILE:%.c=%.o)
SRCS_PATH=	$(addprefix $(SRCS_DIR)/,$(DIRS))

vpath %.c $(SRCS_PATH)
vpath %.h $(HDRS_DIR)
vpath %.o $(OBJS_DIR)
vpath %.a $(LIBS_DIRS)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS_FILE)
	@echo Checking libft
	@make -C libft bonus
	@make -C libmlx
	@echo Build all .o in $@
	@make real

real: $(OBJS_FILE)
	$(CC) $^ $(FLAGS) -I$(HDRS_DIR) $(LIBS_LINK) $(FRM) -o $(NAME)

%.o: %.c
	@echo Compiling $< in $@
	$(CC) -c $< $(FLAGS) -I$(HDRS_DIR) -o $(OBJS_DIR)/$@

$(OBJS_DIR):
	mkdir -p $@

clean: 
	@echo Cleaning .o file...
	@rm -rf $(OBJS_DIR)
	@echo Done!

fclean: clean
	@echo Remove $(NAME)
	@rm -f $(NAME)

re: fclean all

norme:
	@clear && clear
	@norminette libft/*.h
	@norminette libft/*.c
	@norminette $(HDRS_DIR)
	@norminette $(SRCS_DIR)

recl:
	@make re && make clean

%:
	@echo "Can't find rule for target $@"
