# installation
apt install apache2, subversion, libapache2-mod-svn

# repo creation
mkdir repos_dir
mkdir repo
svnadmin create repos_dir/repo/

chown -R www-data:www-data repos_dir
chmod -R 755 repos_dir

# file with passwords
htpasswd -c passwds ix
htpasswd passwds user1

# modules
ls /etc/apache2/mods-available
a2enmod dav_svn
a2enmod authz_svn


# https
a2enmod rewrite
a2enmod ssl
a2ensite default-ssl

