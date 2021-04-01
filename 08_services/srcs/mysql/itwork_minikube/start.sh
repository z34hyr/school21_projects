
#telegraf &
openrc boot
/etc/init.d/mariadb setup
rc-service mariadb start

# echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
# echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
# echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
# echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
# mysql wordpress -u root --skip-password < ./wordpress.sql

echo "create database wordpress;" | mysql
echo "grant all on *.* to admin@'%' identified by 'admin' with grant option; flush privileges;" | mysql
mysql wordpress < wordpress.sql

rc-service mariadb stop
/usr/bin/mysqld_safe
