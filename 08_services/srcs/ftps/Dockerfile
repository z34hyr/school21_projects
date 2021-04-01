
FROM alpine:3.12

RUN apk update
RUN apk add vsftpd bash openssl sudo

RUN apk add --no-cache telegraf --repository https://alpine.global.ssl.fastly.net/alpine/edge/community/

RUN openssl req -nodes -x509 -newkey rsa:4096 -days 365 \
				-keyout /etc/ssl/certs/ftps.key \
				-out /etc/ssl/certs/ftps.crt \
				-subj '/C=RU/ST=Moscow/L=Moscow/O=IgorCO/CN=localhost'

RUN adduser -D admin
RUN echo 'admin:admin' | chpasswd

RUN mkdir /etc/telegraf
RUN cp /etc/telegraf.conf /etc/telegraf/
RUN sed -i "s~# urls = \[\"http://127.0.0.1:8086\"\]~urls = \[\"http://influxdb-svc:8086\"\]~g" /etc/telegraf/telegraf.conf
RUN sed -i "s~# database = \"telegraf\"~database = \"db_ftps\"~g" /etc/telegraf/telegraf.conf

RUN rm /etc/vsftpd/vsftpd.conf
COPY ./vsftpd.conf /etc/vsftpd/
COPY ./start.sh /

VOLUME /sys/fs/cgroup

EXPOSE 20 21 30020 30021
ENTRYPOINT ["sh", "start.sh"]