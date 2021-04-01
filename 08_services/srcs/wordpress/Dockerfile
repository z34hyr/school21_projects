
FROM alpine:3.12

RUN apk update
RUN apk add bash wget nginx sudo
RUN apk add php7 php7-fpm php7-mysqli php7-json

RUN apk add --no-cache telegraf --repository https://alpine.global.ssl.fastly.net/alpine/edge/community/

RUN apk add wget
RUN apk add openrc --no-cache

RUN mkdir /etc/telegraf
RUN cp /etc/telegraf.conf /etc/telegraf/
RUN sed -i "s~# urls = \[\"http://127.0.0.1:8086\"\]~urls = \[\"http://influxdb-svc:8086\"\]~g" /etc/telegraf/telegraf.conf
RUN sed -i "s~# database = \"telegraf\"~database = \"db_wordpress\"~g" /etc/telegraf/telegraf.conf

COPY ./start.sh /

#RUN rm /etc/nginx/conf.d/default.conf
#COPY ./nginx.conf /etc/nginx/conf.d/nginx.conf
RUN rm /etc/nginx/nginx.conf
COPY ./nginx.conf /etc/nginx/ 
RUN echo "pid /var/run/nginx/nginx.pid;" >> /etc/nginx/nginx.conf
RUN mkdir /var/run/nginx
RUN touch /var/run/nginx/nginx.pid

RUN mkdir -p /usr/share/webapps/
RUN cd /usr/share/webapps/
RUN wget http://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN rm latest.tar.gz
RUN mkdir /www
#RUN adduser -D -g 'admin' admin
#RUN chown -R admin:admin /var/lib/nginx
#RUN chown -R admin:admin /www
RUN mv ./wordpress /www
COPY ./wp-config.php /www/wordpress

EXPOSE 5050
CMD ["nginx", "-g", "daemon off;"]
ENTRYPOINT ["sh", "start.sh"]