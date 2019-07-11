#!/bin/sh
cnt=0
#read addr&ip from wldevlist
get_addr() {
	local time=`date`
	local ip
	local mac_addr
	uci show wldevlist | grep "device" | sed 's/=.*$//g' > /addr.txt
	echo "##############test start at $time################ " > /tmp/deauth.txt
	while read line
	do
		online=`uci -q get ${line}.online`
		if [ "$online" == 1  ]; then
			ip=`uci -q get ${line}.ip`
			mac_addr=`echo "$line" | sed 's/^.*\.//g'`""
			eval "ip$cnt=$ip"
			eval "addr$cnt=$mac_addr"
			eval "echo \"station: $cnt mac_addr \$addr$cnt ip \$ip$cnt >>>>>>>>>>>\" >> /tmp/deauth.txt"
			let "cnt++"
		fi
	done < /addr.txt
	echo "ping connect test start, $cnt stations in total." > /dev/console
}

#parse base on $cnt
parse_station() {
	local time
	local ip
	local mac_addr
	local num=$cnt
	let "num--"
	until [ $num -lt 0 ]
	do
		eval "mac_addr=\$addr$num"
		eval "ip=\$ip$num"
		ping -c 1 ${ip} >/dev/null 2>&1
		[ "$?" == 1 ] && {
			time=`date`
			echo "$time: ping $ip failed, mac_addr is ${mac_addr}     " >> /tmp/deauth.txt
		}
		let "num--"
	done
}

get_addr
while true
do
	parse_station
	sleep 1
done
