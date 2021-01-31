# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enena <enena@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 19:20:55 by enena             #+#    #+#              #
#    Updated: 2021/01/25 17:49:54 by enena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
MAINTAINER Eiji Nena enena@student.21-school.ru
EXPOSE 80 443

RUN mkdir /home/srcs
COPY ./srcs /home/srcs

RUN apt-get update
RUN apt-get upgrade
RUN apt-get install -y nginx
RUN apt-get install -y wget
RUN apt-get install -y curl
RUN apt-get install -y default-mysql-server
RUN apt-get install -y php7.3-cli php7.3-fpm php7.3-mysql php7.3-zip php7.3-mbstring php7.3-curl
RUN apt-get install -y vim toilet
#PHPMYADMIN
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz
RUN tar -xf phpMyAdmin-5.0.4-all-languages.tar.gz -C /var/www/html/
RUN mv /var/www/html/phpMyAdmin-5.0.4-all-languages /var/www/html/phpMyAdmin
RUN rm -f phpMyAdmin-5.0.4-all-languages.tar.gz

CMD ["sh", "/home/srcs/main_scrpt.sh"]
