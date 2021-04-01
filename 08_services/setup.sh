
minikube start --driver=virtualbox

eval $(minikube docker-env)

minikube addons enable metallb
kubectl apply -f srcs/metallb/metallb.yaml

docker build -t wordpress_im srcs/wordpress/
kubectl apply -f srcs/wordpress/wordpress.yaml

docker build -t nginx_im srcs/nginx/
kubectl apply -f srcs/nginx/nginx.yaml

docker build -t mysql_im srcs/mysql/
kubectl apply -f srcs/mysql/mysql.yaml

docker build -t phpmyadmin_im srcs/phpmyadmin/
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml

docker build -t ftps_im srcs/ftps/
kubectl apply -f srcs/ftps/ftps.yaml

docker build -t influxdb_im srcs/influxdb/
kubectl apply -f srcs/influxdb/influxdb.yaml

docker build -t grafana_im srcs/grafana/
kubectl apply -f srcs/grafana/grafana.yaml
