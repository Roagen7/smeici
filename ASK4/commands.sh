# installation
apt install apache2, subversion, libapache2-mod-svn

# repo creation
mkdir repos_dir
mkdir repo
svnadmin create repos_dir/repo/

chown www-data:www-data repos_dir -R
chmod u+rwx,g+rw repos_dir -R

# file with passwords
htpasswd -c passwds ix
htpasswd passwds user1

# modules
ls /etc/apache2/mods-available
a2enmod dav_svn
a2enmod authz_svn

