openrc boot
#rc-service nginx start
/etc/init.d/sshd start

telegraf &
nginx -g "daemon off;"