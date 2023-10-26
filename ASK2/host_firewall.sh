#!/bin/bash

echo "Dominik Lau"

# cleanup
iptables -F
iptables -F -t nat
iptables -X -t nat
iptables -F -t filter
iptables -X -t filter


# drop all incoming packets
iptables -P FORWARD ACCEPT
iptables -P INPUT DROP
iptables -P OUTPUT ACCEPT

iptables -A INPUT -i lo -j ACCEPT
iptables -A INPUT -i enp0s8 -j ACCEPT
iptables -A INPUT -i enp0s3 -j ACCEPT
iptables -A INPUT -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT

# enable port forwarding
sysctl -w net.ipv4.ip_forward=1

# NAT

# enp0s8 - internal, enp0s3 - external
iptables -A FORWARD -i enp0s8 -s 10.0.0.0/24 -d 0/0 -j ACCEPT
iptables -A FORWARD -i enp0s3 -s 0/0 -d 10.0.0.0/24 -j ACCEPT
iptables -t nat -A POSTROUTING -s 10.0.0.0/24 -d 0/0 -j MASQUERADE

# port forwarding
iptables -A PREROUTING -t nat -i enp0s3 -p tcp -d 192.168.56.103 --dport 1234 -j DNAT --to-destination 10.0.0.2:22

iptables -A PREROUTING -t nat -i enp0s8 -p tcp -d 10.0.0.1 --dport 1234 -j DNAT --to-destination 10.0.0.2:22

iptables -A FORWARD -i enp0s8 -o enp0s3 -j ACCEPT
