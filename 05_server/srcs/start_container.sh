# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start_container.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 12:01:50 by qmalcom           #+#    #+#              #
#    Updated: 2020/08/26 12:07:22 by qmalcom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# to build image:
# sudo docker build -t test_a ~/school21/path_to_Dockerfile
#
# to delete image:
# sudo docker rmi -f test_a
#
# to run docker:
# sudo docker run -it -p 80:80 -p 443:443 test_a
#
# to switch autoindex:
# from server's bash type:
# sh autoind_switch.sh

# starts mysql, then create new DB + user
service mysql start
mysql -u root mysql < ./tmp/mysql-conf.sql
service mysql restart

#changing default configs
rm -f /var/www/html/phpmyadmin/config.inc.php
mv ./tmp/config.inc.php /var/www/html/phpmyadmin

rm -f /var/www/html/wordpress/wp-config-sapmle.php
rm -f /var/www/html/wordpress/wp-config.php
mv ./tmp/wp-config.php /var/www/html/wordpress

service nginx start
rm -f /etc/nginx/sites-available/default
mv ./tmp/default /etc/nginx/sites-available/

service php7.3-fpm start
service nginx restart
#sleep infinity & wait
bash