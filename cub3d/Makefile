# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enena <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 17:51:07 by enena             #+#    #+#              #
#    Updated: 2021/01/23 21:20:20 by enena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

.PHONY: all bonus clean fclean re norme recl

CC = gcc

NAME = cub3d

SRC_NAME =  

FLAGS = -Wall -Wextra -Werror -Ihdrs

FRM = -lmlx -L. -lft -Llibft -framework OpenGL -framework AppKit

O_FILE = $(addsuffix .o, $(SRC_NAME))

all: $(NAME)

$(NAME): ./*.c hdrs/*.h
	$(CC) $(filter %.c, $^) $(FLAGS) $(FRM) -o $@

clean: 
	@rm -f 

fclean: clean
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
