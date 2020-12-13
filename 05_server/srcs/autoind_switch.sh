# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    autoind_switch.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 11:13:38 by qmalcom           #+#    #+#              #
#    Updated: 2020/08/26 11:25:34 by qmalcom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if grep "autoindex on" /etc/nginx/sites-available/default
then
	sed -i "s/autoindex on/autoindex off/" /etc/nginx/sites-available/default
elif grep "autoindex off" /etc/nginx/sites-available/default
then
	sed -i "s/autoindex off/autoindex on/" /etc/nginx/sites-available/default
fi
service nginx restart