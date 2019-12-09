#!/bin/bash
#sed -i 's/__INLINE //g' $1
cnt=0
sta() {
	while [ $cnt -lt 3 ]
	do
		let "cnt++"
	done
	echo "$cnt"
}
sta
