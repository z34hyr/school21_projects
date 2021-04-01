
FROM alpine:3.12

RUN apk update
RUN apk add bash wget sudo mysql mysql-client
RUN apk add openrc --no-cache

RUN apk add --no-cache telegraf --repository https://alpine.global.ssl.fastly.net/alpine/edge/community/

RUN mkdir /etc/telegraf
RUN cp /etc/telegraf.conf /etc/telegraf/
RUN sed -i "s~# urls = \[\"http://127.0.0.1:8086\"\]~urls = \[\"http://influxdb-svc:8086\"\]~g" /etc/telegraf/telegraf.conf
RUN sed -i "s~# database = \"telegraf\"~database = \"db_mysql\"~g" /etc/telegraf/telegraf.conf

COPY ./start.sh /
COPY ./my.cnf /etc/mysql
#COPY ./mysql_conf.sql /
COPY ./wordpress.sql /

VOLUME /var/lib/mysql

EXPOSE 3306
ENTRYPOINT ["sh", "start.sh"]