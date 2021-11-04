# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enena <enena@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 23:43:02 by enena             #+#    #+#              #
#    Updated: 2021/11/03 17:37:59 by enena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	philo

SRCS =	philo.c\
		get_options.c\
		init_info.c\
		init_mutex.c\
		init_philos.c\
		philo_life.c\
		time_utils.c\
		print_utils.c

HDRS =	philo.h

OBJS =	$(SRCS:%.c=%.o)

CC =	gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
	@norminette *.c
	@norminette *.h
