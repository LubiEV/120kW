#!/bin/sh

option="${1}" 

case ${option} in
	-wc)
		echo "wifi connect"
		rm -f /etc/wpa_supplicant.conf
		#wirelessname=`ls /sys/class/net | grep wlan* | head -1`		
                ifconfig wlan0 up > /dev/null 2>&1&
                killall wpa_supplicant > /dev/null 2>&1&
#		iwconfig wlan0 power off > /dev/null 2>&1 &		
		wpa_passphrase $2 $3 >> /etc/wpa_supplicant.conf
                wpa_supplicant -B -D wext -i wlan0 -c /etc/wpa_supplicant.conf > /dev/null 2>&1&
		sleep 5
                udhcpc -i wlan0 > /dev/null 2>&1&
		;;
	-wd)
		echo "wifi disconnect"
		killall wpa_supplicant
	#	rm -f /etc/wpa_supplicant.conf
	#	wirelessname=`ls /sys/class/net | grep wlan* | head -1`
		ifconfig wlan0 down
		;;
	-ec)	
		echo "ethernet connect"
	        ifconfig eth1 $2 netmask $4
	        route add default gw $3 eth1
		;;
	-ed)
		echo "ethernet disconnect"
                ifconfig eth1 down
		;;
	
	-gc)	
#		killall quectel-CM 
		quectel-CM -s $2 $3&	
		echo "gsm connect"			        	        
		;;
	-gd)
		echo "gsm disconnect"
                killall quectel-CM
		;;
esac
exit
