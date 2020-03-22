FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install wget

#install nginx
RUN apt-get -y install nginx
#install MYSQL
RUN apt-get -y install mariadb-server
#install PHP
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

COPY ./srcs/nginx.conf /etc/nginx/sites-available/default
COPY ./srcs/phpinfo.php /var/www/html
COPY ./srcs/wp-config.php ./tmp/wp-config.php

#install phpmyadmin
WORKDIR /var/www/html/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin
# SSL
RUN openssl req -x509 -nodes -days 365 -subj "/C=KR/ST=Korea/L=Seoul/O=innoaca/OU=42seoul/CN=jhur" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt; 
#계정사용자가 홈디렉토리에 접속해도 소유권이 모두 www-data 이기에 업로드/수정이 불가능하게 된다.
RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

COPY ./srcs/init.sh ./
CMD bash init.sh