# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/23 18:49:07 by qmalcom           #+#    #+#              #
#    Updated: 2020/08/26 11:26:44 by qmalcom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade

RUN apt-get -y install nano
RUN apt-get -y install wget
RUN apt-get -y install nginx

RUN apt-get -y install php7.3 php7.3-common \
			php7.3-cli php7.3-fpm \
			php7.3-gd php7.3-mysql \
			php7.3-curl php7.3-simplexml \
			php7.3-zip

ADD https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz phpmyadmin.tar.gz
RUN tar xvf phpmyadmin.tar.gz
RUN mv ./phpMyAdmin-* /var/www/html/phpmyadmin

RUN apt-get -y install mariadb-server

ADD https://wordpress.org/latest.tar.gz latest.tar.gz
RUN tar -zxvf latest.tar.gz
RUN mv ./wordpress /var/www/html/
RUN chown www-data.www-data /var/www/html/wordpress/* -R

RUN apt-get -y install openssl
RUN openssl req -nodes -x509 -newkey rsa:4096 -days 365 \
				-keyout /etc/ssl/certs/mysite.key \
				-out /etc/ssl/certs/mysite.crt \
				-subj '/C=RU/ST=Moscow/L=Moscow/O=IgorCO/CN=localhost'

COPY ./srcs/mysql-conf.sql ./tmp
COPY ./srcs/wp-config.php ./tmp
COPY ./srcs/default ./tmp
COPY ./srcs/autoind_switch.sh ./
COPY ./srcs/config.inc.php ./tmp
COPY ./srcs/start_container.sh ./

CMD bash start_container.sh