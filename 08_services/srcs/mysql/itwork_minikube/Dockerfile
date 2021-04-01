
FROM alpine:latest

RUN apk update
RUN apk add bash wget sudo mysql mysql-client
RUN apk add openrc --no-cache

COPY ./start.sh /
COPY ./my.cnf /etc/mysql
#COPY ./mysql_conf.sql /
COPY ./wordpress.sql /

VOLUME /var/lib/mysql

EXPOSE 3306
ENTRYPOINT ["sh", "start.sh"]