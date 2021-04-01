
FROM alpine:3.12

RUN apk update
RUN apk add bash wget sudo

RUN apk add --no-cache telegraf --repository https://alpine.global.ssl.fastly.net/alpine/edge/community/

RUN wget https://dl.grafana.com/enterprise/release/grafana-enterprise-7.3.7.linux-amd64.tar.gz
RUN tar -zxvf grafana-enterprise-7.3.7.linux-amd64.tar.gz

RUN mkdir /etc/telegraf
RUN cp /etc/telegraf.conf /etc/telegraf/
RUN sed -i "s~# urls = \[\"http://127.0.0.1:8086\"\]~urls = \[\"http://influxdb-svc:8086\"\]~g" /etc/telegraf/telegraf.conf
RUN sed -i "s~# database = \"telegraf\"~database = \"db_grafana\"~g" /etc/telegraf/telegraf.conf

RUN apk add --repository http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat

COPY ./start.sh /

EXPOSE 3000
ENTRYPOINT ["sh", "start.sh"]