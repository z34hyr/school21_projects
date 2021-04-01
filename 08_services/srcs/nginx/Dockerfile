
FROM alpine:3.12

RUN apk update
RUN apk add nginx bash openssl openssh sudo
RUN apk add openrc --no-cache

RUN apk add --no-cache telegraf --repository https://alpine.global.ssl.fastly.net/alpine/edge/community/

RUN mkdir /etc/telegraf
RUN cp /etc/telegraf.conf /etc/telegraf/
RUN sed -i "s~# urls = \[\"http://127.0.0.1:8086\"\]~urls = \[\"http://influxdb-svc:8086\"\]~g" /etc/telegraf/telegraf.conf
RUN sed -i "s~# database = \"telegraf\"~database = \"db_nginx\"~g" /etc/telegraf/telegraf.conf

RUN adduser -D -g 'www' www
RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www

RUN openssl req -nodes -x509 -newkey rsa:4096 -days 365 \
				-keyout /etc/ssl/certs/mysite.key \
				-out /etc/ssl/certs/mysite.crt \
				-subj '/C=RU/ST=Moscow/L=Moscow/O=IgorCO/CN=localhost'

#RUN rm /etc/nginx/nginx.conf
#COPY ./nginx.conf /etc/nginx/nginx.conf
RUN rm /etc/nginx/conf.d/default.conf
COPY ./nginx.conf /etc/nginx/conf.d/nginx.conf
RUN echo "pid /var/run/nginx/nginx.pid;" >> /etc/nginx/nginx.conf
RUN mkdir /var/run/nginx
RUN touch /var/run/nginx/nginx.pid

RUN rm /etc/ssh/ssh_config
RUN rm /etc/ssh/sshd_config

COPY ./ssh_config /etc/ssh/
COPY ./sshd_config /etc/ssh/

RUN adduser -D admin
RUN echo 'admin:admin' | chpasswd
RUN /usr/bin/ssh-keygen -A
RUN echo "Hello, it's a qmalcom SSH Welcome page! You're in nginx apline-base container!" > /etc/motd

COPY ./index.html /www/
COPY ./start.sh /

EXPOSE 22 80 443
CMD ["nginx", "-g", "daemon off;"]
ENTRYPOINT ["sh", "start.sh"]