sudo sysctl -w net.ipv4.ip_forward=1
sudo nano /etc/sysctl.conf -> net.ipv4.ip_forward = 1

sudo iptables -t nat -A POSTROUTING -o wlo1 -j MASQUERADE
sudo iptables -A FORWARD -i wlo1 -o enp3s0 -m state --state RELATED,ESTABLISHED -j ACCEPT
sudo iptables -A FORWARD -i enp3s0 -o wlo1 -j ACCEPT

sudo ip addr add 192.168.1.1/24 dev enp3s0
sudo ip link set dev enp3s0 up
sudo nano /etc/dnsmasq.conf ->  interface=enp3s0
                                dhcp-range=192.168.1.50,192.168.1.150,12h
                                port=5353

sudo systemctl restart dnsmasq

tx2: 10.128.112.250