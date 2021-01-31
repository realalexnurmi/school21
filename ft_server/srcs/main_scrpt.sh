#HELLO
clear
toilet -k -f pagga -F border welcome to enena\'s ft_server -w 120
#ADD NGINX CONF
mv /home/srcs/nginx.conf /etc/nginx/sites-available
ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled
#CREATE DATABASE
service mysql start
service php7.3-fpm start
echo "CREATE USER 'admin'@'localhost' IDENTIFIED BY '1234';" | mysql -u root --skip-password
echo "CREATE DATABASE myDB;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON myDB.* TO 'admin'@'localhost';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
echo "CREATE DATABASE wp_database;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wp_database.* TO 'admin'@'localhost';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
#SET WORDPRESS
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
cd /var/www/html
wp core download --allow-root
wp core config --allow-root --dbname=wp_database --dbuser=admin --dbpass=1234 --dbhost=localhost --dbprefix=wp_
wp core install --allow-root --url="localhost"  --title="21school" --admin_user="admin" --admin_password="1234" --admin_email="enena@student.21-school.ru"
cd /
#phpMyAdmin
mv /home/srcs/phpMyAdmin-conf.php /var/www/html/phpMyAdmin/.
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.pem -keyout /etc/nginx/ssl/localhost.key -subj "/C=RU/ST=Tatarstan/L=Kazan/O=21school/OU=enena/CN=ft_server"
service nginx start
bash
