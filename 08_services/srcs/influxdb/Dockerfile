
FROM alpine:3.12

RUN apk update
RUN apk add bash wget sudo
RUN apk add --upgrade influxdb
RUN apk add --no-cache telegraf --repository https://alpine.global.ssl.fastly.net/alpine/edge/community/
RUN apk add openrc --no-cache

RUN mkdir /etc/telegraf
RUN cp /etc/telegraf.conf /etc/telegraf/
RUN sed -i "s~# urls = \[\"http://127.0.0.1:8086\"\]~urls = \[\"http://127.0.0.1:8086\"\]~g" /etc/telegraf/telegraf.conf
RUN sed -i "s~# database = \"telegraf\"~database = \"db_influx\"~g" /etc/telegraf/telegraf.conf

COPY ./start.sh /

EXPOSE 8086
ENTRYPOINT ["sh", "start.sh"]
